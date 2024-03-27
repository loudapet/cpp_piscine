/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:29 by plouda            #+#    #+#             */
/*   Updated: 2024/03/27 15:33:06 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define PADDING 60

const std::string	basicTest("Basic test");
const std::string	gradesLowTest("Constructor exception 1");
const std::string	gradesHighTest("Constructor exception 2");
const std::string	incDecTest("Increment & decrement");
const std::string	incDecTestFunc("Increment & decrement (function)");
const std::string	incDecException("Increment & decrement exception");
const std::string	incDecFuncException("Increment & decrement (function) exception");


const std::string	diffExceptionCatch("out_of_range exception");

void	startSection(const std::string& title)
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

int	main()
{
	startSection(basicTest);
	try
	{
		Bureaucrat	high("Justin", 3);
		Bureaucrat	low("Moonie", 148);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(gradesLowTest);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		Bureaucrat	imposter("Imposter", 151);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(gradesHighTest);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		Bureaucrat	imposter("Imposter", -1);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(incDecTest);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << ++high << std::endl;
		std::cout << --low << std::endl;
		std::cout << high++ << std::endl;
		std::cout << low-- << std::endl;
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(incDecException);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << ++high << std::endl;
		std::cout << --low << std::endl;
		std::cout << high++ << std::endl;
		std::cout << low-- << std::endl;
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		// breaking point
		std::cout << high++ << std::endl;
		std::cout << low-- << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	startSection(incDecTestFunc);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		high.gradeUp();
		low.gradeDown();
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		high.gradeDown(10);
		low.gradeUp(10);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(incDecFuncException);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 148);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		high.gradeUp();
		low.gradeDown();
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		// breaking point
		high.gradeDown(1000);
		low.gradeUp(1000);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	startSection(diffExceptionCatch);
	try
	{
		Bureaucrat	high("High", 3);
		Bureaucrat	low("Low", 147);
		Bureaucrat	imposter("Imposter", -1);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << imposter << std::endl;
	}
	catch(const std::out_of_range& e) // notice the change here, ::logic_error is also acceptable
	{
		std::cerr << e.what() << std::endl;
	}
	endSection();
	return (0);
}