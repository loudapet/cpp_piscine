/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:09:19 by plouda            #+#    #+#             */
/*   Updated: 2024/04/11 12:13:11 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>void printArrayContents(Array<T> array)
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int	main()
{
	std::cout << "Initialized array: ";
	Array<int>	empty;
	Array<int>	digits(10);
	printArrayContents(digits);
	
	std::cout << "Array with digits: ";
	for (size_t i = 0; i < digits.size(); i++)
		digits[i] = i;
	printArrayContents(digits);

	std::cout << "New digit arrays with a replaced member" << std::endl;
	Array<int> newDigits(digits);
	Array<int> evenNewerDigits = digits;
	newDigits[5] = 100;
	evenNewerDigits[5] = -1;
	printArrayContents(digits);
	printArrayContents(newDigits);
	printArrayContents(evenNewerDigits);

	std::cout << "Accessing invalid indexes" << std::endl;
	try
	{
		digits[-1];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		digits[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Array of doubles: ";
	Array<double>	doubleDigits(10);
	for (size_t i = 0; i < doubleDigits.size(); i++)
		doubleDigits[i] = i + i/2.;
	printArrayContents(doubleDigits);
}