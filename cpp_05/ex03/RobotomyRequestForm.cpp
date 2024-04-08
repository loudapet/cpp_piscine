/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:43:06 by plouda            #+#    #+#             */
/*   Updated: 2024/04/08 08:51:32 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), _target("Not specified")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& refObj) : 
	AForm("RobotomyRequestForm", 72, 45)
{
	_target = refObj._target;
	*this = refObj;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& refObj)
{
	if (this != &refObj)
		this->_target = refObj._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::checkIfExecutable(executor);
	srand(time(0));
	if (rand() % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy request failed." << std::endl;
}

