/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:43:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/19 11:14:45 by plouda           ###   ########.fr       */
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

int	main()
{
	ClapTrap	Clappy("Clappy");
	ScavTrap	Scavvy("Scavvy");
	FragTrap	Fraggy("Fraggy");

	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);
	std::cout << std::endl;
	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");
	std::cout << std::endl;
	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	std::cout << std::endl;
	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);
	std::cout << std::endl;
	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	std::cout << std::endl;
	Clappy.takeDamage(10);
	Scavvy.takeDamage(100);
	Fraggy.takeDamage(100);
	std::cout << std::endl;
	Clappy.attack("Target");
	Scavvy.attack("Target");
	Fraggy.attack("Target");
	Clappy.beRepaired(1);
	Scavvy.beRepaired(1);
	Fraggy.beRepaired(1);
	std::cout << std::endl;
	Scavvy.guardGate();
	Fraggy.highFivesGuys();
	std::cout << std::endl;
	displayAttributes(Clappy);
	displayAttributes(Scavvy);
	displayAttributes(Fraggy);

	return (0);
}