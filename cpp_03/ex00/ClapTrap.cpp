/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:39:54 by plouda            #+#    #+#             */
/*   Updated: 2024/03/15 12:14:41 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Anonymous"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Anonymous ClapTrap was constructed!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " + name + " was constructed!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& refObj)
{
	*this = refObj;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& refObj)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Bzzzz... " + _name + " destroyed..." << std::endl;
	return ;
}

void	ClapTrap::setName(const std::string name)
{
	_name = name;
}

void	ClapTrap::setHp(unsigned int amount)
{
	_hp = amount;
}

void	ClapTrap::setEp(unsigned int amount)
{
	_ep = amount;
}

void	ClapTrap::setAd(unsigned int amount)
{
	_ad = amount;
}

const std::string&	ClapTrap::getName() const
{
	return (_name);
}

int	ClapTrap::getHp() const
{
	return (_hp);
}

int	ClapTrap::getEp() const
{
	return (_ep);
}

int	ClapTrap::getAd() const
{
	return (_ad);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_ep > 0 && _hp > 0)
	{
		_ep--;
		std::cout << "ClapTrap " + _name + " attacks " + target + ", ";
		std::cout << "causing " << _ad << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " + _name + " cannot act" << std::endl;
	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	std::cout << "ClapTrap " + _name + " suffers " << amount << " ";
	std::cout << "points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0 && _hp > 0)
	{
		_ep--;
		_hp += amount;
		std::cout << "ClapTrap " + _name + " repairs itself for ";
		std::cout << amount << std::endl;
	}
	else
		std::cout << "ClapTrap " + _name + " cannot act" << std::endl;
}
