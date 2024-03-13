/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:41:28 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 12:01:58 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():	_x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	return ;
}

Point::Point(const Fixed& x, const Fixed& y): _x(x), _y(y)
{
	return ;
}

Point::Point(const Point& refObj)
{
	*this = refObj;
}

// Cannot assign const variables
Point&	Point::operator=(const Point& rhs)
{
	(void)rhs;
	return (*this);
}

Point::~Point()
{
	return ;
}

const Fixed&	Point::getX() const
{
	return (this->_x);
}

const Fixed&	Point::getY() const
{
	return (this->_y);
}

Point	Point::operator+(const Point& rhs) const
{
	Fixed	x_pos;
	Fixed	y_pos;

	x_pos = this->getX() + rhs.getX();
	y_pos = this->getY() + rhs.getY();
	return (Point(x_pos, y_pos));
}


Point	Point::operator-(const Point& rhs) const
{
	Fixed	x_pos;
	Fixed	y_pos;

	x_pos = this->getX() - rhs.getX();
	y_pos = this->getY() - rhs.getY();
	return (Point(x_pos, y_pos));
}
