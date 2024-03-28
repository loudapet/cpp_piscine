/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:29 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 12:32:56 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define PADDING 60

const std::string	basicTest("Basic test");
const std::string	gradesLowTest("Constructor exception 1");
const std::string	gradesHighTest("Constructor exception 2");
const std::string	signFormRight("Signing form 1");
const std::string	signFormWrong("Signing form 2");
const std::string	signFormSigned("Signing form 3");

const std::string	diffExceptionCatch("invalid_argument exception");

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
	startTest(basicTest);
	try
	{
		Bureaucrat	high("Justin", 3);
		Bureaucrat	low("Moonie", 148);
		Form		form("29B", 10, 10);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(gradesLowTest);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		Form	imposterForm("Imposter", 151, 151);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposterForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(gradesHighTest);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		Form	imposterForm("Imposter", 30, 0);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposterForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(signFormRight);
	try
	{
		Bureaucrat	high("High", 30);
		Form		form("Crewmate", 30, 1);
		std::cout << high << std::endl;
		std::cout << form << std::endl;
		high.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(signFormWrong);
	try
	{
		Bureaucrat	high("High", 30);
		Form		form("Crewmate", 29, 1);
		std::cout << high << std::endl;
		std::cout << form << std::endl;
		high.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(signFormSigned);
	try
	{
		Bureaucrat	high("High", 30);
		Bureaucrat	low("Low", 99);
		Form		form("Crewmate", 100, 1);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << form << std::endl;
		high.signForm(form);
		std::cout << form << std::endl;
		low.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startTest(diffExceptionCatch);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 147);
		Form		imposterForm("Imposter form", -1, 0);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposterForm << std::endl;
	}
	catch(const std::invalid_argument& e) // notice the change here, ::logic_error is also acceptable
	{
		std::cerr << e.what() << std::endl;
	}
	endSection();
	return (0);
}