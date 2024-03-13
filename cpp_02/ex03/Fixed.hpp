/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:17 by plouda            #+#    #+#             */
/*   Updated: 2024/03/12 16:49:25 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_FRACTIONALBITS;
	
	public:

		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingNb);
		Fixed(const Fixed& oldObj);
		Fixed&	operator=(const Fixed& oldObj);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator<(const Fixed& right) const;
		bool	operator>(const Fixed& right) const;
		bool	operator>=(const Fixed& right) const;
		bool	operator<=(const Fixed& right) const;
		bool	operator==(const Fixed& right) const;
		bool	operator!=(const Fixed& right) const;
		Fixed	operator+(const Fixed& right) const;
		Fixed	operator-(const Fixed& right) const;
		Fixed	operator*(const Fixed& right) const;
		Fixed	operator/(const Fixed& right) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		static Fixed&		min(Fixed& first, Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);
		
};

std::ostream&	operator<<(std::ostream &outputStream, const Fixed &fixedNb);

#endif