/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:24:25 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 14:40:03 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	_type = "ice";
	std::cout << "Ice ❆ created" << std::endl;
	return ;
}

Ice::Ice(const Ice& refObj) : AMateria()
{
	_type = refObj._type;
}

Ice& Ice::operator = (const Ice& refObj)
{
	(void)refObj;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice ❆ destroyed" << std::endl;
	return ;
}

AMateria*	Ice::clone() const
{
	AMateria*	newMateria = new Ice;

	return (newMateria);
}

void 		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() << std::endl;
}

