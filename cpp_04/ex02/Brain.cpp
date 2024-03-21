/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:38:28 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 09:57:58 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain online!" << std::endl;
	return ;
}

Brain::Brain(const Brain& refObj)
{
	*this = refObj;
}

Brain& Brain::operator = (const Brain& refObj)
{
	if (this != &refObj)
	{
		for (int i = 0 ; i < 100 ; i++)
			_ideas[i] = refObj._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain offline" << std::endl;
	return ;
}
