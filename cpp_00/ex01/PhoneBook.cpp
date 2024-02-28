/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:27:39 by plouda            #+#    #+#             */
/*   Updated: 2024/02/28 14:29:27 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

PhoneBook::PhoneBook()
{
	return ;
}

void	PhoneBook::addContact()
{
	int	flag = 0;

	_shiftContactDataQueue();
	flag += this->_contactList[0].setFirstName();
	if (!flag)
		flag += this->_contactList[0].setLastName();
	if (!flag)
		flag += this->_contactList[0].setNickname();
	if (!flag)
		flag += this->_contactList[0].setPhoneNumber();
	if (!flag)
		flag += this->_contactList[0].setDarkestSecret();
	if (!flag)
	{
		std::cout << GRN << "Contact successfully saved!" << CRESET << std::endl;
		std::cout << std::endl;
	}
}

void	PhoneBook::_shiftContactDataQueue()
{
	for (int i = 7 ; i > 0 ; i--)
		_contactList[i] = _contactList[i-1];
}

void	PhoneBook::_displayHeader() const
{
	for (int i = 0 ; i < 45 ; i++)
		std::cout << "=";
	std::cout << std::endl << "|" << INV << "   Index   " << "First name " << " Last name " << " Nickname " << CRESET << "|" << std::endl; 
	for (int i = 0 ; i < 45 ; i++)
		std::cout << "=";
	std::cout << std::endl;
}

void	PhoneBook::_displayPhonebookDataAsList(std::string string) const
{
	size_t	len = 0;
	int		whitespaceCount;
	int		characterCount = 0;

	len = string.length();
	if (len <= 10)
		whitespaceCount = 10 - len;
	else
		whitespaceCount = 0;
	while (whitespaceCount)
	{
		std::cout << " ";
		characterCount++;
		whitespaceCount--;
	}
	for (int i = 0 ; characterCount < 10 && string[i] ; i++)
	{
		if (characterCount == 9 && string[i+1])
			std::cout << ".";
		else
			std::cout << string[i];
		characterCount++;
	}
	std::cout << "|";
}

int PhoneBook::_retrieveIndexFromUser() const
{
	std::string	index;
	int			indexNb;

	std::cout << "Enter valid index number to display contact information:" << std::endl;
	std::getline(std::cin, index);
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << std::endl;
		return (-1);
	}
	if (index.length() > 1 || !isdigit(index[0]) || index[0] >= '8')
	{
		std::cerr << RED << "Invalid index number, must be a single digit in range 0-7" << CRESET << std::endl;
		return (-1);
	}
	indexNb = index[0] - '0';
	if (_contactList[indexNb].getFirstName() == "")
	{
		std::cerr << RED << "Contact with such index does not exist yet" << CRESET << std::endl;
		return (-1);
	}
	return (indexNb);
}

void PhoneBook::displayContactList() const
{
	std::string	firstName;
	std::string	index;
	std::stringstream	sstream;
	int			indexNb;
	Contact		contactToDisplay;

	if (_contactList[0].getFirstName() == "")
		std::cout << YEL << "No contacts to display just yet"<< CRESET << std::endl;
	else
	{
		_displayHeader();
		for (int i = 0 ; i < 8 ; i++)
		{
			firstName = _contactList[i].getFirstName();
			if (firstName != "")
			{
				sstream << i;
				sstream >> index;
				sstream.clear();
				std::cout << "|";
				_displayPhonebookDataAsList(index);
				_displayPhonebookDataAsList(firstName);
				_displayPhonebookDataAsList(_contactList[i].getLastName());
				_displayPhonebookDataAsList(_contactList[i].getNickname());
				std::cout << std::endl;
			}
		}
		for (int i = 0 ; i < 45 ; i++)
			std::cout << "=";
		std::cout << std::endl;
		indexNb = _retrieveIndexFromUser();
		if (indexNb >= 0)
			_contactList[indexNb].displayContactData();
	}
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}