/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:20:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 14:12:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point	a(0.,0.);
	const Point	b(0.,10.);
	const Point c(10.,0.);
	const Point testedPoint(5,5);

	std::cout << (bsp(a, b, c, testedPoint) ? "in" : "out") << std::endl;
	return 0;
}