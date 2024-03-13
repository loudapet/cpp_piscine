/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:20:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 12:47:48 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point	a(0.,0.);
	const Point	b(0.,10.);
	const Point c(10.,0.);
	const Point testedPoint(1,1);

	std::cout << "a: " << a.getX() << "," << a.getY() << std::endl;
	std::cout << "b: " << b.getX() << "," << b.getY() << std::endl;
	std::cout << "c: " << c.getX() << "," << c.getY() << std::endl;
	std::cout << "test: " << testedPoint.getX() << "," << testedPoint.getY() << std::endl;
	std::cout << bsp(a, b, c, testedPoint);
	return 0;
}