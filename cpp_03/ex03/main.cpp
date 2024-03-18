/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:43:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/18 11:32:35 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"
# include <cstdlib>
# include <ctime>

void	displayAttributes(ClapTrap& clapTrap)
{
	std::cout << "Name: " << clapTrap.getName() << std::endl;
	std::cout << "HP: " << clapTrap.getHp() << std::endl;
	std::cout << "EP: " << clapTrap.getEp() << std::endl;
	std::cout << "AD: " << clapTrap.getAd() << std::endl;	
}

int	main()
{
	ClapTrap	Clappy("Clappy");
	ScavTrap	Scavvy("Scavvy");
	FragTrap	Fraggy("Fraggy");
	DiamondTrap	Dimmy("Dimmy");

	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);
	displayAttributes(Dimmy);

	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");
	Dimmy.DiamondTrap::attack("Target");

/* 	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	Dimmy.beRepaired(1);

	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);
	Dimmy.takeDamage(100);

	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	Dimmy.beRepaired(1);

	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);
	Dimmy.takeDamage(100);

	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");
	Dimmy.attack("Target");
	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	Dimmy.beRepaired(1);

	Scavvy.guardGate();
	Fraggy.highFivesGuys();

	Dimmy.guardGate();
	Dimmy.highFivesGuys();
	Dimmy.whoAmI();
	
	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);
	displayAttributes(Dimmy); */

	return (0);
}