/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:17:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:22:33 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << CLR3 << "WrongCat born!" << CRESET << std::endl;
	_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat& refObj)
{
	*this = refObj;
}

WrongCat& WrongCat::operator = (const WrongCat& refObj)
{
	if (this != &refObj)
		this->_type = refObj._type;
	return (*this);

}

WrongCat::~WrongCat()
{
	std::cout << CLR3 << "WrongCat gone!" << CRESET << std::endl;
	return ;
}

void	WrongCat::makeSound() const
{
	std::cout << CLR3 << "Uhhhm... mew?" << CRESET << std::endl;
}
