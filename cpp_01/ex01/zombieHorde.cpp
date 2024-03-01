/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:21 by plouda            #+#    #+#             */
/*   Updated: 2024/03/01 12:41:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde;
	//std::stringstream	stream;

	horde = new Zombie[N];
	for (int i = 0 ; i < N ; i++)
	{
		//stream << i;
		//horde[i].setName(name + stream.str());
		horde[i].setName(name);
		//horde[i].announce();
		//stream.str("");
	}
	return (horde);
}