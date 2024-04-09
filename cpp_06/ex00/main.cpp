/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:01:05 by plouda            #+#    #+#             */
/*   Updated: 2024/04/09 10:44:48 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, const char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(std::string(argv[1]));
	}
	//std::cout << std::fixed << std::numeric_limits<float>::max() << std::endl;
	return (0);
}