/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:16:12 by plouda            #+#    #+#             */
/*   Updated: 2024/04/12 13:05:58 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

template <typename Container>
void	easyfind(const Container& container, int toFind)
{
	std::stringstream	sstream;
	std::string			message;
	sstream << toFind;
	sstream >> message; 
	std::cout << "Element ";
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw (std::runtime_error(message + std::string(" not found")));
	else
	{
		//std::cout << "Element found at position " << std::distance(container.begin(), std::find(container.begin(), container.end(), toFind)) << std::endl;
		std::cout << message + std::string(" found") << std::endl;
	}
}

#endif  // EASYFIND_HPP
