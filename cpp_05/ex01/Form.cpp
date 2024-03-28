/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:51:21 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 12:32:41 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	return ;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExec) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (gradeToSign < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (gradeToExec > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (gradeToExec < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

Form::Form(const Form& refObj) : _name(refObj._name), _signed(refObj._signed),
	_gradeToSign(refObj._gradeToSign), _gradeToExec(refObj._gradeToExec)
{
	*this = refObj;
}

// does not really make sense due to many attributes being constant
Form& Form::operator = (const Form& refObj)
{
	(void)refObj;
	return (*this);
}

Form::~Form()
{
	return ;
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

const int &Form::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &Form::getGradeToExec() const
{
	return (_gradeToExec);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	_signed = true;
}

Form::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("")
{
	return ;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

Form::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("")
{
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

std::ostream &operator<<(std::ostream &outputStream, const Form &form)
{
	outputStream << form.getName() << ((form.getSigned()) ? " is signed " : " is not signed ");
	outputStream << "and requires grade " << form.getGradeToSign() << " to sign ";
	outputStream << "and grade " << form.getGradeToExec() << " to execute.";
	return (outputStream);
}
