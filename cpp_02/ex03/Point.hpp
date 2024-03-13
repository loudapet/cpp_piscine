/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:21:48 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 12:13:59 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	
	public:

		Point();
		Point(const float x, const float y);
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& rhs);
		Point&	operator=(const Point& rhs);
		Point	operator+(const Point& rhs) const;
		Point	operator-(const Point& rhs) const;
		~Point();
		const Fixed&	getX() const;
		const Fixed&	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
