/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:42:53 by plouda            #+#    #+#             */
/*   Updated: 2024/03/01 12:54:43 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The memory address of the string variable: ";
	std::cout << &string << std::endl;
	
	std::cout << "The memory address held by stringPTR: ";
	std::cout << &stringPTR << std::endl;
	
	std::cout << "The memory address held by stringREF: ";
	std::cout << &stringREF << std::endl;

	std::cout << "The value of the string variable: ";
	std::cout << string << std::endl;

	std::cout << "The value pointed to by stringPTR: ";
	std::cout << *stringPTR << std::endl;

	std::cout << "The value pointed to by stringREF: ";
	std::cout << stringREF << std::endl;
}