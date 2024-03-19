/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:23:10 by plouda            #+#    #+#             */
/*   Updated: 2024/03/19 12:52:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	ScavTrap	tempS;

	_name = "Anonymous";
	ClapTrap::_name = _name + "_clap_name";
	_ep = tempS.getEp();
	std::cout << "Anonymous DiamondTrap formed after hundreds of thousands of years!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	ScavTrap	tempS;

	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_ep = tempS.getEp();
	std::cout << "DiamondTrap " + _name + " formed after hundreds of thousands of years!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& refObj) : ClapTrap(refObj), ScavTrap(refObj), FragTrap(refObj) 
{
	*this = refObj;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& refObj)
{ 
	if (this != &refObj)
	{
		this->_name = refObj._name;
		this->_hp = refObj._hp;
		this->_ep = refObj._ep;
		this->_ad = refObj._ad;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Ooops, down the drain " + _name + " goes!" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << _name << std::endl;
	std::cout << ClapTrap::_name << std::endl;
}

int	DiamondTrap::getAd() const
{
	return (DiamondTrap::_ad);
}
