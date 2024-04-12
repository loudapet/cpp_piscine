/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:00:17 by plouda            #+#    #+#             */
/*   Updated: 2024/04/11 12:20:29 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cerrno>
# include <cstdlib>
# define INT_CHARS "+-0123456789"
# define FLOAT_CHARS "+-0123456789.f"
# define DOUBLE_CHARS "+-0123456789."
# define SPECIAL_CHARS "+-.f"

struct Values
{
	unsigned char	c;
	int		i;
	float	f;
	double	d;
};

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
	PSEUDO
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& refObj);
		ScalarConverter& operator = (const ScalarConverter& refObj);
		~ScalarConverter();
	public:
		static void	convert(const std::string value);
};

typedef void (*Convert)(const std::string&, Values*);
typedef void (*Print)(const std::string&, Values*);

#endif  // SCALARCONVERTER_HPP
