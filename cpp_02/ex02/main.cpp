/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:20:33 by plouda            #+#    #+#             */
/*   Updated: 2024/03/13 15:53:07 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main( void )
{
	Fixed a;
	Fixed const b( Fixed( -5.05f ) * Fixed( -2 ) );
	std::cout << a << std::endl;	
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */

int main( void )
{
	//Fixed a;
	Fixed a(1);
	Fixed const b( Fixed( 5.05f ) * Fixed( -2 ) );
	Fixed const c(2000.002f);
	Fixed const d(-1.5f);
	Fixed const e(2.55f);
	std::cout << a << std::endl;	
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << c << std::endl;

	std::cout << "Now testing division of " << a << "/" << b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << a.toFloat() / b.toFloat() << std::endl;
	std::cout << "Now testing division of " << d << "/" << e << std::endl;
	std::cout << d / e << std::endl;
	std::cout << d.toFloat() / e.toFloat() << std::endl;


	return 0;
}