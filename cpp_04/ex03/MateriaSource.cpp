/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:05:49 by plouda            #+#    #+#             */
/*   Updated: 2024/03/25 12:25:46 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "New source of magic created" << std::endl;
	for (int i = 0; i < 4; i++)
		_sourceInventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& refObj)
{
	std::cout << "New source of magic copy constructed" << std::endl;
	(void)refObj;
	for (int i = 0; i < 4; i++)
		_sourceInventory[i] = NULL;
	return ;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& refObj)
{
	std::cout << "New source of magic used copy assignment operator" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_sourceInventory[i] != NULL)
			_sourceInventory[i] = refObj._sourceInventory[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_sourceInventory[i] != NULL)
		{
			delete _sourceInventory[i];
			_sourceInventory[i] = NULL;
		}
	std::cout << "New source of magic destroyed" << std::endl;
	return ;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia != NULL)
	{
		int i = 0;
		while (i < 4 && _sourceInventory[i] != NULL)
			i++;
		if (i != 4)
		{
			_sourceInventory[i] = materia;
			std::cout << "Source of magic learned " + _sourceInventory[i]->getType() + " materia" << std::endl;
		}
		else
			std::cout << "No space left to learn more materia" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *newMateria;

	int i = 0;
	while (i < 4 && _sourceInventory[i] != NULL && _sourceInventory[i]->getType() != type)
		i++;
	if (i != 4)
	{
		newMateria = _sourceInventory[i]->clone();
		std::cout << "Source of magic created new " + newMateria->getType()+ " materia "<< std::endl;
	}
	else
	{
		newMateria = NULL;
		std::cout << "Source of magic did not create new materia" << std::endl;
	}
	return (newMateria);
}
