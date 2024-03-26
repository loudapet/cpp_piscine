/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:20:00 by plouda            #+#    #+#             */
/*   Updated: 2024/03/26 11:13:14 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type(""), _inInventory(false)
{
	//std::cout << "Default ◎ created" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type), _inInventory(false)
{
	//std::cout << "Default ◎ created" << std::endl;
	return ;
}


AMateria::AMateria(const AMateria& refObj)
{
	*this = refObj;
}

AMateria& AMateria::operator = (const AMateria& refObj)
{
	if (this != &refObj)
		_type = refObj._type;
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "Default ◎ scrapped" << std::endl;
	return ;
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "uses Materia at " << target.getName() << std::endl;
	return ;
}

void	AMateria::setInInventory(bool value)
{
	_inInventory = value;
}

bool	AMateria::getInInventory() const
{
	return (_inInventory);
}

