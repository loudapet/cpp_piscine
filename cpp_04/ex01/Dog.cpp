/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:28 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 11:56:34 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_brain = new Brain();
	std::cout << CLR2 << "Dog born!" << CRESET << std::endl;
	_type = "Dog";
	return ;
}

Dog::Dog(const Dog& refObj)
{
	if (refObj._brain)
		_brain = new Brain(*refObj._brain);
	else
		_brain = NULL;
	_type = refObj._type;
}

Dog& Dog::operator = (const Dog& refObj)
{
	this->_type = refObj._type;
	*this->_brain = *refObj._brain;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << CLR2 << "Dog gone!" << CRESET << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << CLR2 << "Woof woof" << CRESET << std::endl;
}

void	Dog::brainScanner() const
{
	std::cout << "Brain address: " << _brain << std::endl;
}
