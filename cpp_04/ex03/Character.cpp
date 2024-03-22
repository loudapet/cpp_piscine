/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:55:45 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 17:06:00 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria* Character::_floor[100];

Character::Character() : ICharacter()
{
	_name = "Anonymous";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character(std::string name) : ICharacter()
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character(const Character& refObj)
{
	_name = refObj._name;
	/* for (int i = 0; _inventory[i] != NULL && i < 4; i++)
		delete _inventory[i]; */
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			_inventory[i] = refObj._inventory[i]->clone();
}

Character& Character::operator = (const Character& refObj)
{
	std::cout << "Character's copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = refObj._inventory[i]->clone();
	return (*this);
}

Character::~Character()
{
	std::cout << "CHARACTER IS FUCKING GONE" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	return ;
}

std::string	const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && _inventory[i] != NULL)
		i++;
	if (i != 4)
		_inventory[i] = m;
}

void Character::unequip(int idx)
{
	int	i = 0;
	if (idx >= 0 && idx <= 3)
	{
		while (i < 100 && _floor[i] != NULL)
			i++;
		_floor[i] = _inventory[idx];
		_inventory[i] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
		else
			std::cout << "No slotted materia" << std::endl;
	}
}

void	Character::emptyFloor()
{
	for (int i = 0; i < 100 ; i++)
		delete _floor[i];
}

const std::string& Character::getMateria(int idx) const
{
	return (_inventory[idx]->getType());
}