/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/12 12:25:16 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FRACTIONALBITS = 8;

Fixed::Fixed():	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	_value = integer << _FRACTIONALBITS;
}

Fixed::Fixed(const float floatingNb)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatingNb * (1 << _FRACTIONALBITS));
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

std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb)
{
	outputStream << fixedNb.toFloat();
	return (outputStream);
}


int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	return ;
}

int		Fixed::toInt(void) const
{
	return (_value >> _FRACTIONALBITS);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _FRACTIONALBITS));
}

