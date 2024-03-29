/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:45:49 by plouda            #+#    #+#             */
/*   Updated: 2024/03/19 11:54:09 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Anonymous";
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "Anonymous FragTrap was assembled!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap " + _name + " was assembled!" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& refObj) : ClapTrap(refObj)
{
	*this = refObj;
}

FragTrap& FragTrap::operator = (const FragTrap& refObj)
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

FragTrap::~FragTrap()
{
	std::cout << "Cling-clang... " + _name + " disassembled..." << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << " is displaying a positive high-five request." << std::endl;
}
