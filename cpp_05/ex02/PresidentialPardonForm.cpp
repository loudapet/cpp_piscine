/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:30 by plouda            #+#    #+#             */
/*   Updated: 2024/03/29 10:40:53 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), _target("Not specified")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& refObj) : 
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = refObj._target;
	*this = refObj;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& refObj)
{
	if (this != &refObj)
		this->_target = refObj._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::checkIfExecutable(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

