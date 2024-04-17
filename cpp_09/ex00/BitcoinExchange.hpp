/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:17 by plouda            #+#    #+#             */
/*   Updated: 2024/04/17 16:50:19 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <climits>
#include <errno.h>
#define DATE_CHARS "0123456789-"
#define VALUE_CHARS "0123456789."

class BitcoinExchange
{
	private:
		std::map<int, double>	_exchangeRates;
		BitcoinExchange();

		void					_loadExchangeRates(std::ifstream& exchangeRatesDB);
		void					_processBtcValues(std::ifstream& exchangeRates);
		void					_executeExchange(std::string& date, std::string& value);

	public:
		BitcoinExchange(const char* pathExchangeRates, const char* pathBtcValues);
		BitcoinExchange(const BitcoinExchange& refObj);
		BitcoinExchange& operator = (const BitcoinExchange& refObj);
		~BitcoinExchange();
};

#endif  // BITCOINEXCHANGE_HPP
