/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:09:47 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:10:26 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << CLR1 << "WrongAnimal born!" << CRESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& refObj)
{
	*this = refObj;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

WrongAnimal::~WrongAnimal()
{
	std::cout << CLR1 << "WrongAnimal gone!" << CRESET << std::endl;
	return ;
}

void	WrongAnimal::makeSound() const
{
	std::cout << CLR1 << "Unintelligible WrongAnimal sound" << CRESET << std::endl;
}

const std::string&	WrongAnimal::getType() const
{
	return (this->_type);
}