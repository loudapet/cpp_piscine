/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:29 by plouda            #+#    #+#             */
/*   Updated: 2024/04/01 12:10:33 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestWrapper.hpp"
#define PADDING 80

/*
- High = 3, Low = 148
- ShrubberyCreationForm: Required grades: sign 145, exec 137
- RobotomyRequestForm: Required grades: sign 72, exec 45
- PresidentialPardonForm: Required grades: sign 25, exec 5
*/
std::string	testArray[] =	{"Basic test", 
							"executing Shrubbery form",
							"executing Shrubbery form - low grade",
							"executing Shrubbery form - not signed",
							"executing Robotomy form",
							"executing Robotomy form - low grade",
							"executing Robotomy form - not signed",
							"executing Pardon form",
							"executing Pardon form - low grade",
							"executing Pardon form - not signed"};

void	startTest(const std::string& title)
{
	std::string newTitle = std::string(CRESET) + YEL + " [" + title + "] " + CRESET + GREY;
	int padding = PADDING - title.size() - 4; // 4 stands for extra characters in newTitle without ANSI strings
	int pad = padding / 2;
	if (pad > 0)
		std::cout << GREY + std::string(padding, '~').insert(pad, newTitle) + CRESET << std::endl;
	else
		std::cout << std::string(YEL) + " [" + title + "] " + CRESET << std::endl;
}

void	endSection()
{
	std::cout << GREY + std::string(PADDING, '~') + CRESET << std::endl;
}

int	main(int argc, const char **argv)
{
	(void)argc;
	startTest(std::string(argv[0]));
	for (unsigned long i = 0; i < sizeof(testArray)/sizeof(testArray[0]); i++)
	{
		startTest(testArray[i]);
		try
		{
			TestWrapper	test(i);
			std::cout << test.getHigh() << std::endl;
			std::cout << test.getLow() << std::endl;
			test.test(testArray[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	endSection();
	return (0);
}