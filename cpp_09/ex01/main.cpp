/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:09:35 by plouda            #+#    #+#             */
/*   Updated: 2024/04/18 15:05:36 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	doOperation(int& lhs, int& rhs, char& op)
{
	switch (op)
	{
		case '-':
			return (lhs - rhs);
		case '*':
			return (lhs * rhs);
		case '/':
			return (lhs / rhs);
		default:
			return (lhs + rhs);
	}
}

static bool	isSign(char& c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	main(int argc, const char **argv)
{
	if (argc != 2)
		return (std::cout << "Program expects one argument only" << std::endl, 1);
	std::stack<int>	stack;
	std::string		rpn = argv[1];
	for (size_t i = 0; rpn[i]; i++)
	{
		if (!isdigit(rpn[i]) && !isspace(rpn[i]) && !isSign(rpn[i]))
			return (std::cout << "Error: invalid character encountered" << std::endl, 1);
		else if (isdigit(rpn[i]))
			stack.push(rpn[i] - '0');
		else if (isSign(rpn[i]))
		{
			if (stack.size() < 2)
				return (std::cout << "Error: invalid syntax" << std::endl, 1);
			int	rhs = stack.top();
			if (!rhs && rpn[i] == '/')
				return (std::cout << "Domain error: division by 0" << std::endl, 1);
			stack.pop();
			int	lhs = stack.top();
			stack.pop();
			stack.push(doOperation(lhs, rhs, rpn[i]));
		}
	}
	if (stack.size() != 1)
		return (std::cout << "Error: more than one number left" << std::endl, 1);
	std::stringstream	sstr;
	std::string			res;
	sstr << stack.top();
	sstr >> res;
	std::cout << res << std::endl;
	return (0);
}