/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:42:36 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 12:49:47 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Fixed	crossProductOrientation(const Point& v1, const Point& v2)
{
	Fixed nb = v1.getX() * v2.getY() - v1.getY() * v2.getX();
	return (nb);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Point	AB(b - a);
	const Point	BC(c - b);
	const Point	CA(a - c);
	const Point	AP(point - a);
	const Point	BP(point - b);
	const Point	CP(point - c);

	Fixed	crossA;
	Fixed	crossB;
	Fixed	crossC;
	crossA = crossProductOrientation(AB, AP);
	crossB = crossProductOrientation(BC, BP);
	crossC = crossProductOrientation(CA, CP);

	if ((crossA > 0 && crossB > 0 && crossC > 0)
		|| (crossA < 0 && crossB < 0 && crossC < 0))
		return (true);
	return (false);
}