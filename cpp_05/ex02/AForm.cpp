/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:51:21 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 10:44:04 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	return ;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name),
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

AForm::AForm(const AForm& refObj) : _name(refObj._name), _signed(refObj._signed),
	_gradeToSign(refObj._gradeToSign), _gradeToExec(refObj._gradeToExec)
{
	*this = refObj;
}

// does not really make sense due to many attributes being constant
AForm& AForm::operator = (const AForm& refObj)
{
	(void)refObj;
	return (*this);
}

AForm::~AForm()
{
	return ;
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

const int &AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	_signed = true;
}

void	AForm::checkIfExecutable(Bureaucrat const & executor) const
{
	if (!_signed)
		throw(NotSignedException());
	if (executor.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
}

AForm::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("")
{
	return ;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

AForm::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("")
{
	return ;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

AForm::NotSignedException::NotSignedException() :
	std::logic_error("")
{
	return ;
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The form has not been signed");
}

std::ostream &operator<<(std::ostream &outputStream, const AForm &form)
{
	outputStream << form.getName() << ((form.getSigned()) ? " is signed " : " is not signed ");
	outputStream << "and requires grade " << form.getGradeToSign() << " to sign ";
	outputStream << "and grade " << form.getGradeToExec() << " to execute.";
	return (outputStream);
}
