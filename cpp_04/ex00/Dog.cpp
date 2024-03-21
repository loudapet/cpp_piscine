/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:28 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:02:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << CLR2 << "Dog born!" << CRESET << std::endl;
	_type = "Dog";
	return ;
}

Dog::Dog(const Dog& refObj)
{
	*this = refObj;
}

Dog& Dog::operator = (const Dog& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

Dog::~Dog()
{
	std::cout << CLR2 << "Dog gone!" << CRESET << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << CLR2 << "Woof woof" << CRESET << std::endl;
}