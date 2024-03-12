/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:17 by plouda            #+#    #+#             */
/*   Updated: 2024/03/12 10:40:43 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_FRACTIONALBITS;
	
	public:

		Fixed();
		Fixed(const Fixed& oldObj);
		Fixed& operator=(const Fixed& oldObj);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif