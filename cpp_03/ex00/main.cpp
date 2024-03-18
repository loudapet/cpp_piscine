/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:43:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/18 09:28:35 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
# include <cstdlib>
# include <ctime>

void	displayAttributes(ClapTrap& clapTrap);

void	takeAction(ClapTrap& clapTrap, ClapTrap& target, int action)
{
	unsigned int	heal;
	if (action == 1)
	{
		clapTrap.attack(target.getName());
		if (clapTrap.getEp() > 0)
			target.takeDamage(clapTrap.getAd());
	}
	else if (action == 2)
	{
		heal = rand() % 4 + 1;
		clapTrap.beRepaired(heal);
	}
}

void	fight(ClapTrap& player, ClapTrap& enemy)
{
	unsigned int	action;
	std::string		winner;
	unsigned int	round_counter = 1;

	displayAttributes(player);
	displayAttributes(enemy);
	while ((player.getHp() > 0 && enemy.getHp() > 0)
			&& (player.getEp() > 0 || enemy.getEp() > 0))
	{
		std::cout << "[ ROUND " << round_counter++ << " ]" << std::endl;
		action = rand() % 2 + 1;
		takeAction(player, enemy, action);
		action = rand() % 2 + 1;
		takeAction(enemy, player, action);
	}
	std::cout << "And the winner is..." << std::endl;
	if (player.getHp() > 0 && enemy.getHp() <= 0)
		winner = player.getName();
	else if (enemy.getHp() > 0 && player.getHp() <= 0)
		winner = enemy.getName();
	else
		winner = "Nobody";
	std::cout << winner << "!!!" << std::endl;
}

void	displayAttributes(ClapTrap& clapTrap)
{
	std::cout << "Name: " << clapTrap.getName() << std::endl;
	std::cout << "HP: " << clapTrap.getHp() << std::endl;
	std::cout << "EP: " << clapTrap.getEp() << std::endl;
	std::cout << "AD: " << clapTrap.getAd() << std::endl;
}

void	setAttributes(ClapTrap& clapTrap)
{
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	ad;

	hp = rand() % 10 + 1;
	ep = rand() % 10 + 1;
	ad = rand() % 10 + 1;
	clapTrap.setHp(hp);
	clapTrap.setEp(ep);
	clapTrap.setAd(ad);
}

int	main()
{
	ClapTrap	Default("Mr. Default");
	ClapTrap	Bill("Bill");
	ClapTrap	Jake("Jake");
		
	std::srand(std::time(0));
	setAttributes(Bill);
	setAttributes(Jake);
	fight(Bill, Jake);
	displayAttributes(Bill);
	displayAttributes(Jake);
	

	return (0);
}