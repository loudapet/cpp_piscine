/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 13:54:24 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_FRACTIONALBITS = 8;

Fixed::Fixed():	_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int integer)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = integer << _FRACTIONALBITS;
}

Fixed::Fixed(const float floatingNb)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatingNb * (1 << _FRACTIONALBITS));
}


Fixed::Fixed(const Fixed &oldObj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = oldObj;
	//_value = oldObj._value;
	return ;
}

Fixed&	Fixed::operator=(const Fixed &oldObj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oldObj)
		_value = oldObj.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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

bool	Fixed::operator<(const Fixed& right) const
{
	if (this->_value < right._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed& right) const
{
	return (right < *this);
}

bool	Fixed::operator<=(const Fixed& right) const
{
	return (!(*this > right));
}

bool	Fixed::operator>=(const Fixed& right) const
{
	return (!(*this < right));
}

bool	Fixed::operator==(const Fixed& right) const
{
	if (this->_value == right._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& right) const
{
	return (!(*this == right));
}


Fixed	Fixed::operator+(const Fixed& right) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() + right.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& right) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - right.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& right) const
{
	Fixed	res;

	res._value = (this->_value * right._value) >> _FRACTIONALBITS;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& right) const
{
	Fixed	res;

	res._value = this->_value / right._value << _FRACTIONALBITS;
	return (res);
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	oldValue;

	oldValue._value = this->_value;
	this->_value++;
	return (oldValue);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	oldValue;

	oldValue._value = this->_value;
	this->_value--;
	return (oldValue);
}

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	if (second < first)
		return (second);
	else
		return (first);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	if (second > first)
		return (second);
	else
		return (first);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	if (second < first)
		return (second);
	else
		return (first);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	if (second > first)
		return (second);
	else
		return (first);
}