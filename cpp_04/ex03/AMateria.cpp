/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:20:00 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 15:19:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "";
	std::cout << "Default ◎ created" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
	std::cout << "Default ◎ created" << std::endl;
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
	std::cout << "Default ◎ scrapped" << std::endl;
	return ;
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}

