/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/12 11:25:42 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FRACTIONALBITS = 8;

Fixed::Fixed():	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &oldObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = oldObj;
	//_value = oldObj._value;
	return ;
}

Fixed&	Fixed::operator=(const Fixed &oldObj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oldObj)
		_value = oldObj.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	return ;
}

