/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:20:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/18 14:02:10 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point	a(0.,0.);
	const Point	b(0.,10.);
	const Point c(10.,0.);
	const Point P1(0,0);
	const Point P2(5,5);
	const Point P3(9,10);
	const Point P4(-5,5);
	const Point P5(1,1);

	std::cout << (bsp(a, b, c, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(a, b, c, P2) ? "in" : "out") << std::endl;
	std::cout << (bsp(a, b, c, P3) ? "in" : "out") << std::endl;
	std::cout << (bsp(a, b, c, P4) ? "in" : "out") << std::endl;
	std::cout << (bsp(a, b, c, P5) ? "in" : "out") << std::endl;
	return 0;
}