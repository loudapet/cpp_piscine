/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:29:20 by plouda            #+#    #+#             */
/*   Updated: 2024/04/15 12:41:27 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	{
		Span sp = Span(10);
		sp.addNumber(17);
		sp.addNumber(20);
		sp.addNumber(-13);
		sp.addNumber(10);
		sp.addNumber(1);
		sp.addNumber(7);
		sp.addNumber(4);
		std::cout << "Set of numbers: ";
		sp.printSet();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	// Correct usage
	{
		try
		{
			Span sp = Span(10);
			sp.addNumber(42);
			sp.fillWithNumbers(1,27,3);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// Reversed range
	{
		try
		{
			Span sp = Span(10);
			sp.addNumber(42);
			sp.fillWithNumbers(27,1,3);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// Too many numbers in range of fillWithNumbers
	{
		try
		{
			Span sp = Span(10);
			sp.addNumber(42);
			sp.fillWithNumbers(1,28,3);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// 0 span
	{
		try
		{
			Span sp = Span(0);
			sp.addNumber(42);
			sp.fillWithNumbers(1,27,3);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// 0 span to fillWithNumbers
	{
		try
		{
			Span sp = Span(10);
			sp.addNumber(42);
			sp.fillWithNumbers(1,27,0);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// Multiple duplicates
	{
		try
		{
			Span sp = Span(20);
			sp.addNumber(25);
			sp.addNumber(25);
			sp.addNumber(16);
			sp.fillWithNumbers(1,27,3);
			std::cout << "Set of numbers: ";
			sp.printSet();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// Huge amount
	{
		try
		{
			std::cout << "This might take a moment...";
			std::cout << std::endl;
			Span sp = Span(10001);
			sp.addNumber(19998);
			sp.fillWithNumbers(1,20000,2);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}