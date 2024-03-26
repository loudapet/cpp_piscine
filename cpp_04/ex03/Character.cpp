/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:55:45 by plouda            #+#    #+#             */
/*   Updated: 2024/03/26 11:19:36 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria* Character::_floor[100];

Character::Character() : ICharacter()
{
	_name = "Anonymous";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "Anonymous character is born" << std::endl;
	return ;
}

Character::Character(std::string name) : ICharacter()
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "Character " + _name + " is born" << std::endl;
	return ;
}

Character::Character(const Character& refObj)
{
	//std::cout << _name + "'s copy constructor called" << std::endl;
	_name = refObj._name;
	/* for (int i = 0; _inventory[i] != NULL && i < 4; i++)
		delete _inventory[i]; */
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			_inventory[i] = refObj._inventory[i]->clone();
}

Character& Character::operator = (const Character& refObj)
{
	//std::cout << _name + "'s copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = refObj._inventory[i]->clone();
	return (*this);
}

Character::~Character()
{
	//std::cout << _name + " is gone, RIP" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	return ;
}

std::string	const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	//prevent assignments of one materia to multiple inventories
	if (m->getInInventory())
	{
		std::cerr << m->getType() + " materia is already in a character's inventory" << std::endl;
		return ;
	}
	int i = 0;
	while (i < 4 && _inventory[i] != NULL)
		i++;
	if (i != 4)
	{
		//remove from floor if it had been dropped before
		for (int j = 0; j < 100 ; j++)
		{
			if (m == _floor[j])
			{
				_floor[j] = NULL;
				std::cerr << m->getType() + " materia picked up from the floor" << std::endl;
			}
		}
		_inventory[i] = m;
		_inventory[i]->setInInventory(true);
		//std::cout << _name + " equipped " + m->getType() + " materia" << std::endl;
	}
	else
		std::cerr << _name + "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	int	i = 0;
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
	{
		while (i < 100 && _floor[i] != NULL)
			i++;
		if (i == 100)
		{
			std::cerr << "Floor is full of materia, deleting the most recently dropped one" << std::endl;
			delete _floor[99];
			i = 99;
		}
		_floor[i] = _inventory[idx];
		_inventory[idx] = NULL;
		_floor[i]->setInInventory(false);
		//std::cout << _name + " unequipped " + _floor[i]->getType() + " materia" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
		else
			std::cerr << "No slotted materia" << std::endl;
	}
	else
		std::cerr << "No character has that much space in their bag!" << std::endl;
	if (idx < 0)
		std::cerr << "... or, well, negative space? Since you tried a negative number?" << std::endl;
}

void	Character::emptyFloor()
{
	for (int i = 0; i < 100 ; i++)
	{
		if (_floor[i] != NULL)
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}

const std::string& Character::getMateria(int idx) const
{
	return (_inventory[idx]->getType());
}