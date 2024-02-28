/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:00:20 by plouda            #+#    #+#             */
/*   Updated: 2024/02/28 14:34:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

Contact::Contact() :	_firstName(""), 
						_lastName(""),
						_nickname(""),
						_phoneNumber(""),
						_darkestSecret("")
{	
	return ;
}

int	Contact::setFirstName(void)
{
	do {
		std::cout << UNDER << "First name:" << CRESET << " ";
		std::getline(std::cin, _firstName);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		for (int i = 0 ; _firstName[i] ; i++)
		{
			if (!isprint(_firstName[i]))
			{
				std::cerr << YEL << E_ONLY_PRINTABLE << CRESET << std::endl;
				_firstName = "";
				break ;
			}
		}
	} while (_firstName == "");
	return (0);
}

int	Contact::setLastName(void)
{
	do {
		std::cout << UNDER << "Last name:" << CRESET << " ";
		std::getline(std::cin, _lastName);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		for (int i = 0 ; _lastName[i] ; i++)
		{
			if (!isprint(_lastName[i]))
			{
				std::cerr << YEL << E_ONLY_PRINTABLE << CRESET << std::endl;
				_lastName = "";
				break ;
			}
		}
	} while (_lastName == "");
	return (0);
}

int	Contact::setNickname(void)
{
	do {
		std::cout << UNDER << "Nickname:" << CRESET << " ";
		std::getline(std::cin, _nickname);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		for (int i = 0 ; _nickname[i] ; i++)
		{
			if (!isprint(_nickname[i]))
			{
				std::cerr << YEL << E_ONLY_PRINTABLE << CRESET << std::endl;
				_nickname = "";
				break ;
			}
		}
	} while (_nickname == "");
	return (0);
}

int	Contact::setPhoneNumber(void)
{
	do {
		std::cout << UNDER << "Phone number:" << CRESET << " ";
		std::getline(std::cin, _phoneNumber);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		for (int i = 0 ; _phoneNumber[i] ; i++)
		{
			if (!isdigit(_phoneNumber[i]))
			{
				std::cerr << YEL << "Only digits accepted, try again" << CRESET << std::endl;
				_phoneNumber = "";
				break ;
			}
			if (_phoneNumber.size() > 20)
			{
				std::cerr << YEL << "Number too long, try again" << CRESET << std::endl;
				_phoneNumber = "";
				break ;
			}
			if (_phoneNumber.size() < 9)
			{
				std::cerr << YEL << "Number too short, try again" << CRESET << std::endl;
				_phoneNumber = "";
				break ;
			}
		}
	} while (_phoneNumber == "");
	return (0);
}

int	Contact::setDarkestSecret(void)
{
	do {
		std::cout << UNDER << "Darkest secret:" << CRESET << " ";
		std::getline(std::cin, _darkestSecret);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		for (int i = 0 ; _darkestSecret[i] ; i++)
		{
			if (!isprint(_darkestSecret[i]))
			{
				std::cerr << YEL << E_ONLY_PRINTABLE << CRESET << std::endl;
				_darkestSecret = "";
				break ;
			}
		}
	} while (_darkestSecret == "");
	return (0);
}

void	Contact::resetContact()
{
	_lastName = "";
	_firstName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickname() const
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

void	Contact::displayContactData() const
{
	std::cout << std::endl;
	std::cout << UNDER << "First name" << CRESET << "     : " <<_firstName << std::endl;
	std::cout << UNDER << "Last name" << CRESET << "      : " << _lastName << std::endl;
	std::cout << UNDER << "Nickname" << CRESET << "       : " <<_nickname << std::endl;
	std::cout << UNDER << "Phone number" << CRESET << "   : " << _phoneNumber << std::endl;
	std::cout << UNDER << "Darkest secret" << CRESET << " : " << _darkestSecret << std::endl;
	std::cout << std::endl;
}

Contact::~Contact()
{
	return ;
}

