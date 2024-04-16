/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:37:52 by plouda            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, const char **argv)
{
	(void)argv;
	if (argc != 2)
		std::cout << "Usage: ./btc <input_file>" << std::endl;
	else
	{
		try
		{
			BitcoinExchange	btc("data.csv", argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}