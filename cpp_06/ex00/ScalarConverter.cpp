/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:00:19 by plouda            #+#    #+#             */
/*   Updated: 2024/04/10 15:19:17 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	precision = 1;

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& refObj)
{
	*this = refObj;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& refObj)
{
	(void)refObj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

static bool isChar(const std::string &value)
{
	return (value.size() == 1);
}

static bool	isFloat(const std::string &value)
{
	return
	(
		value.find_first_not_of(FLOAT_CHARS) == std::string::npos
		&& value.find_first_of('.') == value.find_last_of('.') && value.find_first_of('.') != std::string::npos
		&& value.find_first_of('f') == value.find_last_of('f') && value.find_first_of('f') != std::string::npos
		&& (isdigit(value[value.find_first_of('.') + 1]) || value[value.find_first_of('.') + 1] == 'f')
		&& value[value.find_first_of('f') + 1] == 0
	);
}

static bool	isDouble(const std::string &value)
{
	return
	(
		value.find_first_not_of(DOUBLE_CHARS) == std::string::npos
		&& value.find_first_of('.') == value.find_last_of('.') 
		&& (isdigit(value[value.find_first_of('.') + 1]) || value[value.find_first_of('.') + 1] == 0)
	);
}

static bool	isInteger(const std::string &value)
{
	return (value.find_first_not_of(INT_CHARS) == std::string::npos);
}

static bool	isInvalidSign(const std::string &value)
{
	bool	singleton = false;
	bool	hasSign = value.find_first_of("+-") != std::string::npos;

	singleton = (value.find_first_of("+-") == value.find_last_of("+-"));
	if (!singleton)
		return (true);
	else if (singleton && hasSign)
		return (value.find_last_of("+-") != 0);
	else
		return (false);
}

Type	findType(const std::string &value)
{
	if (value == "nan" || value == "nanf" 
		|| value == "+inf" || value == "+inff"
		|| value == "-inf" || value == "-inff")
		return (PSEUDO);
	else if (isInvalidSign(value))
		return (INVALID);
	else if (isChar(value))
		return (CHAR);
	else if (isInteger(value))
		return (INT);
	else if (isDouble(value))
		return (DOUBLE);
	else if (isFloat(value))
		return (FLOAT);
	return (INVALID);
}

void	castFromDouble(const std::string &string, Values *values)
{
	values->d = std::strtod(string.c_str(), NULL);
	values->c = static_cast<unsigned char>(values->d);
	values->i = static_cast<int>(values->d);
	values->f = static_cast<float>(values->d);
}

void	castFromFloat(const std::string &string, Values *values)
{
	values->f = std::strtof(string.c_str(), NULL);
	values->c = static_cast<unsigned char>(values->f);
	values->i = static_cast<int>(values->f);
	values->d = static_cast<double>(values->f);
}

void	castFromInt(const std::string &string, Values *values)
{
	values->i = std::atoi(string.c_str());
	values->c = static_cast<unsigned char>(values->i);
	values->f = static_cast<float>(values->i);
	values->d = static_cast<double>(values->i);
}

void	castFromChar(const std::string &string, Values *values)
{
	values->c = static_cast<unsigned char>(string[0]);
	values->i = static_cast<int>(values->c);
	values->f = static_cast<float>(values->c);
	values->d = static_cast<double>(values->c);
}

void	printChar(const std::string& string, Values* values, Type type)
{
	if (type == CHAR)
	{
		if (string.size() > 0 && string[0] >= +std::numeric_limits<unsigned char>::min() 
			&& string[0] <= +std::numeric_limits<unsigned char>::max())
		{
			if (isprint(values->c))
				std::cout << "char: " << values->c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
	else
	{
		long	validation = std::strtol(string.c_str(), NULL, 10);
		if (validation >= +std::numeric_limits<unsigned char>::min() 
			&& validation <= +std::numeric_limits<unsigned char>::max())
		{
			if (isprint(values->c))
				std::cout << "char: " << values->c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
}

void	printInt(const std::string& string, Values* values, Type type)
{
	long	validation = std::strtol(string.c_str(), NULL, 10);
	
	if (validation >= std::numeric_limits<int>::min() 
		&& validation <= std::numeric_limits<int>::max())
	{
		if (type != FLOAT || 
			(type == FLOAT && static_cast<long long>(values->f) >= std::numeric_limits<int>::min()
			&& static_cast<long long>(values->f) <= std::numeric_limits<int>::max()))
			std::cout << "int: " << values->i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void	printFloat(const std::string &string, Values* values)
{
	errno = 0;
	std::strtof(string.c_str(), NULL);
	if (errno)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(precision) << values->f << "f" << std::endl;
	}
}

void	printDouble(const std::string &string, Values* values)
{
	errno = 0;
	std::strtod(string.c_str(), NULL);
	if (errno)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(precision) << values->d << std::endl;
}

void	printValues(const std::string &string, Values* values, Type type)
{

	printChar(string, values, type);
	printInt(string, values, type);
	printFloat(string, values);
	printDouble(string, values);
}

void	printPseudo(const std::string &string, Values* values)
{
	if (string == "nan" || string == "nanf")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::quiet_NaN());
		values->d = static_cast<double>(std::numeric_limits<double>::quiet_NaN());
	}
	else if (string == "+inf" || string == "+inff")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::infinity());
		values->d = static_cast<double>(std::numeric_limits<double>::infinity());
	}
	else if (string == "-inf" || string == "-inff")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::infinity() * -1.f);
		values->d = static_cast<double>(std::numeric_limits<double>::infinity() * -1.);
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << values->f << "f" << std::endl;
	std::cout << "double: " << values->d << std::endl;
}

int	getPrecision(const std::string& string, Type type)
{
	int		prec;
	bool	hasDot = string.find_first_of(".") != std::string::npos;
	if (type == DOUBLE && hasDot)
		prec = string.size() - string.find_first_of('.') - 1;
	else if (hasDot)
		prec = string.size() - string.find_first_of('.') - 2;
	else
		prec = 1;
	if (prec <= 0)
		prec = 1;
	return (prec);
}

Type	validityCheck(const std::string& string, Type type)
{
	if (type == INT)
	{
		long	validation = std::strtol(string.c_str(), NULL, 10);
		
		if (validation < std::numeric_limits<int>::min() 
			|| validation > std::numeric_limits<int>::max())
		{		
			return (INVALID);
		}
	}
	else if (type == FLOAT)
	{
		errno = 0;		std::strtof(string.c_str(), NULL);
		if (errno)
			return (INVALID);
	}
	else if (type == DOUBLE)
	{
		errno = 0;
		std::strtod(string.c_str(), NULL);
		if (errno)
			return (INVALID);
	}
	return (type);
}

void	ScalarConverter::convert(const std::string value)
{
	Type	type = validityCheck(value, findType(value));
	Values	values;
	Convert	convertArr[4] = {&castFromChar, &castFromInt, &castFromFloat, &castFromDouble};

	if (type == INVALID)
		std::cerr << "Invalid input" << std::endl;
	else if (type == PSEUDO)
		printPseudo(value, &values);
	else
	{
		if (type == FLOAT || type == DOUBLE)
			precision = getPrecision(value, type);
		convertArr[type](value, &values);
		printValues(value, &values, type);
	}
}

