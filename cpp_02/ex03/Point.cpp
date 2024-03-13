/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:41:28 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 10:13:44 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():	_x(0),
				_y(0)
{
	return ;
}

Point::Point(const float x, const float y)
{
	const Fixed	x_pos(x);
	const Fixed	y_pos(y);

	this->_x = x_pos;
	this->_y = y_pos;
	return ;
}

Point::Point(const Point& refObj)
{
	*this = refObj;
}

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

Point::~Point()
{
	return ;
}