/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:00:19 by plouda            #+#    #+#             */
/*   Updated: 2024/04/08 15:09:56 by plouda           ###   ########.fr       */
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
		&& value.find_first_of('.') == value.find_last_of('.') 
		&& value.find_first_of('f') == value.find_last_of('f') 
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
	return (value.find_first_of("+-") != value.find_last_of("+-"));
}

Type	findType(const std::string &value)
{
	if (value == "nan" || value == "nanf" 
		|| value == "+inf" || value == "+inff"
		|| value == "-inf" || value == "-inff")
		return (PSEUDO);
	else if (isInvalidSign(value))
		return (INVALID);
	else if (value == "+" || value == "-" || value == "." || value == "f")
		return (CHAR);
	else if (isInteger(value))
		return (INT);
	else if (isDouble(value))
		return (DOUBLE);
	else if (isFloat(value))
		return (FLOAT);
	else if (isChar(value))
		return (CHAR);
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

void	printChar(Values* values, long validation)
{
	if (validation > std::numeric_limits<unsigned char>::min() 
		&& validation < std::numeric_limits<unsigned char>::max())
	{
		if (isprint(values->c))
			std::cout << "char: " << values->c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void	printInt(Values* values, long validation)
{
	if (validation > std::numeric_limits<int>::min() 
		&& validation < std::numeric_limits<int>::max())
	{		
		std::cout << "int: " << values->i << std::endl;
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
		std::cout << "float: " << std::fixed << std::setprecision(precision) << values->f << "f" << std::endl;
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

void	printValues(const std::string &string, Values* values)
{
	long	validation = std::strtol(string.c_str(), NULL, 10);

	printChar(values, validation);
	printInt(values, validation);
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
	(void)type;
	int prec = string.size() - string.find_first_of('.') - 1;
	if (prec <= 0)
		prec = 1;
	return (prec);
}

void	ScalarConverter::convert(const std::string value)
{
	Type	type = findType(value);
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
		printValues(value, &values);
	}
}

