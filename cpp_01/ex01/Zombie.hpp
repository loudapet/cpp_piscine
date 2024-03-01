/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:16:55 by plouda            #+#    #+#             */
/*   Updated: 2024/03/01 12:26:23 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string string);
		Zombie(void);
		~Zombie();
		void	announce(void);
		void	setName(std::string string);
};

Zombie* zombieHorde( int N, std::string name );

#endif