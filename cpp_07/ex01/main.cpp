/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:36:18 by plouda            #+#    #+#             */
/*   Updated: 2024/04/10 13:33:28 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void times_two(int &n) 
{
	std::cout << n * 2 << std::endl;
}

void print(std::string &s) 
{
	std::cout << s << std::endl;
}

int main(void) 
{
	int array[] = {1, 2, 3, 4, 5};
	std::cout << "Calling iter using multiply function on array of ints" << std::endl;
	::iter(array, 5, times_two);
	
	
	std::cout << "Calling iter using print function on array of strings" << std::endl;
	std::string strings[] = {"Hello", "42", "Prague"};
	::iter(strings, 3, print);

	double dArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Calling iter using decrement function on array of doubles" << std::endl;
	::iter(dArray, 5, decrement);
}