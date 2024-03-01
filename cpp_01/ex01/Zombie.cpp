/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:16:49 by plouda            #+#    #+#             */
/*   Updated: 2024/03/01 12:25:22 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string string) : name(string)
{
	return ;
}

Zombie::Zombie(void)
{
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string string)
{
	this->name = string;
}

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed" << std::endl;
	return ;
}
