/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:12:21 by plouda            #+#    #+#             */
/*   Updated: 2024/04/01 12:23:03 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern& refObj)
{
	*this = refObj;
}

Intern& Intern::operator = (const Intern& refObj)
{
	(void)refObj;
	return (*this);
}

Intern::~Intern()
{
	return ;
}

AForm*	Intern::newShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::newRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::newPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string formName, const std::string formTarget)
{
 	std::string		testArray[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	createForm		fptrArray[] = {&Intern::newShrubberyCreationForm, &Intern::newRobotomyRequestForm,
									&Intern::newPresidentialPardonForm};
	
	for (int i = 0 ; i < 3 ; i++)
	{
		if (formName == testArray[i])
			return((this->*fptrArray[i])(formTarget));
	}
	throw (UnknownNameException());
	return (NULL);
}

Intern::UnknownNameException::UnknownNameException() : std::invalid_argument("Unknown form")
{
	return ;
}

const char*	Intern::UnknownNameException::what() const throw()
{
	return ("Unknown form");
}

