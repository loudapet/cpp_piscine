/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestWrapper.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:07:10 by plouda            #+#    #+#             */
/*   Updated: 2024/03/30 14:09:42 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTWRAPPER_HPP
#define TESTWRAPPER_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <sstream>

class TestWrapper
{
	private:
		AForm*		_shrubbery;
		AForm*		_robotomy;
		AForm*		_pardon;
		Bureaucrat	_high;
		Bureaucrat	_low;

	public:
		TestWrapper();
		TestWrapper(int testNb);
		TestWrapper(Bureaucrat high, Bureaucrat low, int testNb);
		TestWrapper(const TestWrapper& refObj);
		TestWrapper& operator = (const TestWrapper& refObj);
		~TestWrapper();
		Bureaucrat			getHigh() const;
		Bureaucrat			getLow() const;
		AForm*				getShrubbery() const;
		AForm*				getRobotomy() const;
		AForm*				getPardon() const;

		void				testBasic(const std::string test);
		void				testShrubbery(const std::string test);
		void				testRobotomy(const std::string test);
		void				testPardon(const std::string test);
		void				test(const std::string test);
};

typedef void(TestWrapper::*testForm)(const std::string);

#endif  // TESTWRAPPER_HPP
