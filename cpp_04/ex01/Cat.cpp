/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:48 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 11:50:35 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_brain = new Brain();
	std::cout << CLR3 << "Cat born!" << CRESET << std::endl;
	_type = "Cat";
	return ;
}

Cat::Cat(const Cat& refObj)
{
	if (refObj._brain)
		_brain = new Brain(*refObj._brain);
	else
		_brain = NULL;
	_type = refObj._type;
}

Cat& Cat::operator = (const Cat& refObj)
{
	if (this != &refObj)
	{
		this->_type = refObj._type;
		*this->_brain = *refObj._brain;
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << CLR3 << "Cat gone!" << CRESET << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << CLR3 << "Meow meow" << CRESET << std::endl;
}

void	Cat::brainScanner() const
{
	std::cout << "Brain address: " << _brain << std::endl;
}
