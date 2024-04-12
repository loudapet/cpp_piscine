/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:16:20 by plouda            #+#    #+#             */
/*   Updated: 2024/04/12 12:39:33 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	srand(time(0));

	// Adding random numbers to the vector
	for (int i = 0; i < 10; ++i) {
		vec.push_back(rand() % 100); // Random numbers between 0 and 99
	}

	// Print the vector using an iterator
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	//test easyfind part
	try
	{
		{::easyfind(vec, 42);}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		{::easyfind(vec, 1);}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		{::easyfind(vec, 96);}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
return 0;
}