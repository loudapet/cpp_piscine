/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:47:31 by plouda            #+#    #+#             */
/*   Updated: 2024/03/08 11:56:53 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

void	Harl::debug(void)
{
	std::cerr << "[ DEBUG ]" << std::endl;
	std::cerr << "I love having extra bacon for"
				" my 7XL-double-cheese-triple-pickle-specialketchup burger."
				" I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cerr << "[ INFO ]" << std::endl;
	std::cerr << "I cannot believe adding extra bacon costs more money."
			" You didn't put enough bacon in my burger!"
			" If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cerr << "[ WARNING ]" << std::endl;
	std::cerr << "I think I deserve to have some extra bacon for free."
				" I've been coming for years whereas you started working here"
				" since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cerr << "[ ERROR ]" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now.";
	std::cerr << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	RaiseMessage	fptrArray[4] = {&Harl::debug, &Harl::info,
									&Harl::warning, &Harl::error};

	for (int i = 0 ; i < 4 ; i++)
	{
		if (levelArray[i] == level)
		{
			switch (i)
			{
				case 0:
					(this->*fptrArray[0])();
				case 1:
					(this->*fptrArray[1])();
				case 2:
					(this->*fptrArray[2])();
				case 3:
					(this->*fptrArray[3])();
			}
			break ;
		}
		else if (i == 3)
		{
			std::cerr << "[ Probably complaining about insignificant problems ]";
			std::cerr << std::endl;
		}
	}
}

Harl::~Harl()
{
	return ;
}
