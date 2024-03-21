/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:04:53 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:34:59 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << CLR1 << "Animal born!" << CRESET << std::endl;
	return ;
}

Animal::Animal(const Animal& refObj)
{
	*this = refObj;
}

Animal& Animal::operator = (const Animal& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

Animal::~Animal()
{
	std::cout << CLR1 << "Animal gone!" << CRESET << std::endl;
	return ;
}

void	Animal::makeSound() const
{
	std::cout << CLR1 << "Unintelligible animal sound" << CRESET << std::endl;
}

const std::string&	Animal::getType() const
{
	return (this->_type);
}