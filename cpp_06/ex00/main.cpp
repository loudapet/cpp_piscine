/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:01:05 by plouda            #+#    #+#             */
/*   Updated: 2024/04/08 14:17:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, const char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(std::string(argv[1]));
	}
	return (0);
}