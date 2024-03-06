/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:12:29 by plouda            #+#    #+#             */
/*   Updated: 2024/03/06 12:57:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& newName, Weapon& newWeapon) : _name(newName),
																_weapon(newWeapon)
{
	return ;
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " 
		<< this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	return ;
}