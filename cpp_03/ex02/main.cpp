/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:43:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/18 10:21:40 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <cstdlib>
# include <ctime>

void	displayAttributes(ClapTrap& clapTrap)
{
	std::cout << "Name: " << clapTrap.getName() << std::endl;
	std::cout << "HP: " << clapTrap.getHp() << std::endl;
	std::cout << "EP: " << clapTrap.getEp() << std::endl;
	std::cout << "AD: " << clapTrap.getAd() << std::endl;	
}

/* void	setRandomAttributes(ClapTrap& clapTrap)
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
} */

int	main()
{
	ClapTrap	Default("Mr. Default");
	ClapTrap	Clappy("Clappy");
	ScavTrap	Scavvy("Scavvy");
	FragTrap	Fraggy("Fraggy");

	displayAttributes(Default);
	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);

	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");

	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);

	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);

	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);

	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);

	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");
	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);

	Scavvy.guardGate();
	Fraggy.highFivesGuys();
	
	displayAttributes(Default);
	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);

	return (0);
}