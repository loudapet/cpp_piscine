/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:04:53 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 12:50:50 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << CLR1 << "AAnimal born!" << CRESET << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& refObj)
{
	*this = refObj;
}

AAnimal& AAnimal::operator = (const AAnimal& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

AAnimal::~AAnimal()
{
	std::cout << CLR1 << "AAnimal gone!" << CRESET << std::endl;
	return ;
}

void	AAnimal::makeSound() const
{
	std::cout << CLR1 << "Unintelligible AAnimal sound" << CRESET << std::endl;
}

const std::string&	AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::brainScanner() const
{
	return ;	
}