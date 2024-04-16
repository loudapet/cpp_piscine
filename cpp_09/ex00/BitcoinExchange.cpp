/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:08 by plouda            #+#    #+#             */
/*   Updated: 2024/04/16 13:49:17 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

void	BitcoinExchange::_loadExchangeRates(std::ifstream& exchangeRatesDB)
{
	std::string				line;
	std::string				split;
	while (std::getline(exchangeRatesDB, line))
	{
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
			if (line.find('|') == std::string::npos || line.find_first_of('|') != line.find_last_of('|'))
				throw (std::runtime_error("Line not in proper 'date | value' format"));
			std::getline(stream, date, '|');
			date.erase(std::remove_if(date.begin(), date.end(), isspace), date.end());
			
			



			std::getline(stream, value);
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
		throw (std::invalid_argument("Could not open requested input file"));
	this->_loadExchangeRates(exchangeRatesDB);
	//for (std::map<int, double>::iterator it = _exchangeRates.begin() ; it != _exchangeRates.end(); it++)
	//	std::cout << "Key: " << it->first << " Val: " << it->second << std::endl;
	this->_processBtcValues(btcValuesDB);
	
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
