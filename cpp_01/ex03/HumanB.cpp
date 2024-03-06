/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:27:19 by plouda            #+#    #+#             */
/*   Updated: 2024/03/06 12:54:58 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& newName) :	_name(newName),
												_weapon(NULL)
{
	return ;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with their " 
		<< this->_weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	return ;
}