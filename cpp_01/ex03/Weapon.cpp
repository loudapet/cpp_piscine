/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:50:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/06 12:55:56 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string wp_type) : type(wp_type)
{
	return ;
}

const std::string&	Weapon::getType() const
{
	return (this->type);
}
void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

Weapon::~Weapon()
{
	return ;
}