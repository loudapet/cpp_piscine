/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:17 by plouda            #+#    #+#             */
/*   Updated: 2024/04/16 12:39:43 by plouda           ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map<int, double>	_exchangeRates;
		std::map<int, double>	_btcValues;
		BitcoinExchange();

		void					_loadExchangeRates(std::ifstream& exchangeRatesDB);
		void					_processBtcValues(std::ifstream& exchangeRates);

	public:
		BitcoinExchange(const char* pathExchangeRates, const char* pathBtcValues);
		BitcoinExchange(const BitcoinExchange& refObj);
		BitcoinExchange& operator = (const BitcoinExchange& refObj);
		~BitcoinExchange();
};

#endif  // BITCOINEXCHANGE_HPP
