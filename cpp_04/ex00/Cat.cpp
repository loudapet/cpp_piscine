/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:48 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:02:17 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << CLR3 << "Cat born!" << CRESET << std::endl;
	_type = "Cat";
	return ;
}

Cat::Cat(const Cat& refObj)
{
	*this = refObj;
}

Cat& Cat::operator = (const Cat& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

Cat::~Cat()
{
	std::cout << CLR3 << "Cat gone!" << CRESET << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << CLR3 << "Meow meow" << CRESET << std::endl;
}
