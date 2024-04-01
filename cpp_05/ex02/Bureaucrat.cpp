/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:37:52 by plouda            #+#    #+#             */
/*   Updated: 2024/03/29 12:46:16 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string.h>

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& refObj) :
	_name(refObj._name), _grade(refObj._grade)
{
	return ;
}

// does not really make sense due to _name being constant
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& refObj)
{
	if (this != &refObj)
		_grade = refObj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::gradeUp()
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade--;
}
void	Bureaucrat::gradeUp(int value)
{
	if (_grade - value < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade -= value;
}

void	Bureaucrat::gradeDown()
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::gradeDown(int value)
{
	if (_grade + value > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade += value;
}

Bureaucrat&	Bureaucrat::operator++()
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());

	Bureaucrat	oldValue(*this);
	this->_grade--;
	return (oldValue);
}

Bureaucrat&	Bureaucrat::operator--()
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());

	Bureaucrat	oldValue(*this);
	this->_grade++;
	return (oldValue);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << _name << " couldn't execute " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}


Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("Grade is too low")
{
	return ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("Grade is too high")
{
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (outputStream);
}