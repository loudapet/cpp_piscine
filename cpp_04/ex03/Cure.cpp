/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:24:15 by plouda            #+#    #+#             */
/*   Updated: 2024/03/25 11:47:49 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	_type = "cure";
	std::cout << "Cure ✞ created" << std::endl;
	return ;
}

Cure::Cure(const Cure& refObj) : AMateria()
{
	std::cout << "Cure ✞ copy constructor called" << std::endl;
	_type = refObj._type;
}

Cure& Cure::operator = (const Cure& refObj)
{
	std::cout << "Cure ✞ copy assignment operator called" << std::endl;
	(void)refObj;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure ✞ destroyed" << std::endl;
	return ;
}

AMateria*	Cure::clone() const
{
	AMateria*	newMateria = new Cure;

	return (newMateria);
}

void 		Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds" << std::endl;
}
