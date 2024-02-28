/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:01:06 by plouda            #+#    #+#             */
/*   Updated: 2024/02/26 16:57:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "general.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char **argv)
{
	std::string	input;
	PhoneBook	phoneBook;
	int			i = 0;

	(void)argv;
	if (argc == 1)
	{
		while (true)
		{
			if (!std::cin.eof() && !std::cin.fail())
			{
				std::cout << "Supported commands: ADD SEARCH EXIT" << std::endl;
				std::getline(std::cin, input);
			}
			if (std::cin.fail() || std::cin.eof())
			{
				std::cerr << RED << "Reached EOF" << CRESET << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return (0);
			}
			else if (input == "EXIT")
				return (0);
			else if (input == "SEARCH")
				phoneBook.displayContactList();
			else if (input == "ADD")
			{
				phoneBook.addContact(&i);
				i++;
				if (i > 7)
					i = 0;
			}
		}
	}
	return (0);
}