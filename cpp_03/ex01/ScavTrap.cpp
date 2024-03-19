/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:47:50 by plouda            #+#    #+#             */
/*   Updated: 2024/03/19 11:35:04 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "Anonymous";
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "Anonymous ScavTrap was summoned!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap " + _name + " was summoned!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& refObj) : ClapTrap(refObj)
{
	*this = refObj;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& refObj)
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

ScavTrap::~ScavTrap()
{
	std::cout << "Tzbzzztzz... " + _name + " vaporized..." << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << _name << " is now in gate-keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_ep > 0 && _hp > 0)
	{
		_ep--;
		std::cout << "ScavTrap " + _name + " shoots at " + target + ", ";
		std::cout << "causing " << _ad << " damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " + _name + " is exhausted and cannot act" << std::endl;	
}