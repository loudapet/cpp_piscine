/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:08 by plouda            #+#    #+#             */
/*   Updated: 2024/04/17 18:09:47 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

void	BitcoinExchange::_executeExchange(std::string& date, std::string& value)
{
	std::string	oldDate = date;
	date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
	std::stringstream		sstr;
	std::string				exchangedAmount;
	double					amount;
	std::map<int, double>::iterator	iter;
	long	dateNb = std::strtol(date.c_str(), NULL, 10);
	double	valueNb = std::strtod(value.c_str(), NULL);
	iter = _exchangeRates.lower_bound(dateNb);
	amount = iter->second * valueNb;
	sstr << amount;
	sstr >> exchangedAmount;
	std::cout << oldDate << " => " << value << " = " << exchangedAmount << std::endl;
}

void	BitcoinExchange::_loadExchangeRates(std::ifstream& exchangeRatesDB)
{
	std::string				line;
	std::string				split;
	while (std::getline(exchangeRatesDB, line))
	{
		if (line == "date,exchange_rate") // skip header
			continue;

		std::stringstream		stream(line);
		std::string				date;
		std::string				value;
		std::pair<int,double>	keyValuePair;

		std::getline(stream, date, ',');
		std::getline(stream, value);
		date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
		value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
		keyValuePair = std::make_pair(atoi(date.c_str()), strtod(value.c_str(), NULL));
		_exchangeRates.insert(keyValuePair);
	}
}

static void	validateDate(std::string& date, const int lowestDate)
{
	std::stringstream	sstr;
	int					lowestYear;
	std::string			lowestYearStr;
	int					year;
	int					month;
	int					day;

	lowestYear = lowestDate / 10000; // stored in format YYYYMMDD
	sstr << lowestYear;
	sstr >> lowestYearStr;
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw (std::invalid_argument("Improper date format => " + date));
	if (date.find_first_not_of(DATE_CHARS) != std::string::npos)
		throw (std::invalid_argument("Date contains non-digit characters => " + date));
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < lowestYear)
		throw (std::invalid_argument("Year cannot be lower than " + lowestYearStr));
	if (month > 12 || month < 1)
		throw (std::invalid_argument("Month out of range => " + date));
	if (day < 1)
		throw (std::invalid_argument("Day out of range => " + date));
	if (year % 4 || (!(year % 4) && !(year % 100) && year % 400)) // not a leap year
		if (month == 2 && (day > 28))
			throw (std::invalid_argument("Day out of range => " + date));
	if ((month == 2 && day > 29)
		|| (((month % 2 && month < 8) || (!(month % 2) && month > 7)) && day > 31)
		|| (((month % 2 && month > 7) || (!(month % 2) && month < 8)) && day > 30))
		throw (std::invalid_argument("Day out of range => " + date));
}

static void	validateValue(std::string& value)
{
	if (value.find_first_not_of(VALUE_CHARS) != std::string::npos
		|| value.find_first_of('.') != value.find_last_of('.'))
		throw (std::invalid_argument("Value contains invalid characters => " + value));
	errno = 0;
	double	converted = strtod(value.c_str(), NULL);
	if (errno || converted > 1000)
		throw (std::invalid_argument("Btc value too large => " + value));
	if (converted < 0)
		throw (std::invalid_argument("Btc value is not positive => " + value));
}

void	BitcoinExchange::_processBtcValues(std::ifstream& btcValuesDB)
{
	std::string				line;
	std::string				split;
	while (std::getline(btcValuesDB, line))
	{
		std::stringstream		stream(line);
		std::string				date;
		std::string				value;
		try
		{
			if (line.find('|') == std::string::npos || line.find_first_of('|') != line.find_last_of('|')) // pipe char check
				throw (std::runtime_error("Line not in proper 'date | value' format"));
			std::getline(stream, date, '|'); // get everything before pipe
			date.erase(std::remove_if(date.begin(), date.end(), isspace), date.end());
			validateDate(date, _exchangeRates.begin()->first);

			std::getline(stream, value); // get everything after pipe
			value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
			validateValue(value);
			_executeExchange(date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

BitcoinExchange::BitcoinExchange(const char* pathExchangeRates, const char* pathBtcValues)
{
	std::ifstream		exchangeRatesDB;
	std::ifstream		btcValuesDB;

	exchangeRatesDB.open(pathExchangeRates);
	if (!exchangeRatesDB.is_open())
		throw (std::invalid_argument("Could not open exchange rate database"));
	btcValuesDB.open(pathBtcValues);
	if (!btcValuesDB.is_open())
	{
		exchangeRatesDB.close();
		throw (std::invalid_argument("Could not open requested input file"));
	}
	this->_loadExchangeRates(exchangeRatesDB);
	this->_processBtcValues(btcValuesDB);
	exchangeRatesDB.close();
	btcValuesDB.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& refObj)
{
	*this = refObj;
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& refObj)
{
	if (this != &refObj)
		return (*this);
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}
