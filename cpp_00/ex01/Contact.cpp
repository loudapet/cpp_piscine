/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:00:20 by plouda            #+#    #+#             */
/*   Updated: 2024/02/26 16:56:53 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

Contact::Contact() :	_firstName(""), 
						_lastName(""),
						_nickname(""),
						_phoneNumber(""),
						_darkestSecret("")
{	
	//std::cout << "Constructor of Contact called" << std::endl;
}

int	Contact::setFirstName(void)
{
	do {
		std::cout << "First name: ";
		std::getline(std::cin, _firstName);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
	} while (_firstName == "");
	return (0);
}

int	Contact::setLastName(void)
{
	do {
		std::cout << "Last name: ";
		std::getline(std::cin, _lastName);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
	} while (_lastName == "");
	return (0);
}

int	Contact::setNickname(void)
{
	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, _nickname);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
	} while (_nickname == "");
	return (0);
}

int	Contact::setPhoneNumber(void)
{
	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, _phoneNumber);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
	} while (_phoneNumber == "");
	return (0);
}

int	Contact::setDarkestSecret(void)
{
	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, _darkestSecret);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
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
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}


Contact::~Contact()
{
	//std::cout << "Destructor of Contact called" << std::endl;
	return ;
}

