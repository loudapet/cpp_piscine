/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:27:39 by plouda            #+#    #+#             */
/*   Updated: 2024/02/26 17:08:20 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

PhoneBook::PhoneBook()
{
	//std::cout << "Constructor of Phonebook called" << std::endl;
	return ;
}

void	PhoneBook::addContact(int *index)
{
	int	flag = 0;

	flag += this->_contactList[*index].setFirstName();
	flag += this->_contactList[*index].setLastName();
	flag += this->_contactList[*index].setNickname();
	flag += this->_contactList[*index].setPhoneNumber();
	flag += this->_contactList[*index].setDarkestSecret();
	if (flag)
	{
		this->_contactList[*index].resetContact();
		*index -= 1;
	}
}

// Contact*	PhoneBook::_getContact(int index)
// {
// 	return (&(_contactList[index]));
// }

Contact	PhoneBook::_getContact(int index) const
{
	return (_contactList[index]);
}

void	PhoneBook::_displayHeader() const
{
	for (int i = 0 ; i < 44 ; i++)
		std::cout << "=";
	std::cout << std::endl << "|  Index   " << "First name " << " Last name " << "  Nickname|" << std::endl; 
	for (int i = 0 ; i < 44 ; i++)
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

	std::cout << "Please enter index number of the desired contact:" << std::endl;
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
	if (_getContact(indexNb).getFirstName() == "")
	{
		std::cerr << RED << "Contact under such index does not exist yet" << CRESET << std::endl;
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

	if (_getContact(0).getFirstName() == "")
		std::cout << YEL << "No contacts to display just yet"<< CRESET << std::endl;
	else
	{
		_displayHeader();
		for (int i = 0 ; i < 8 ; i++)
		{
			firstName = _getContact(i).getFirstName();
			if (firstName != "")
			{
				sstream << i;
				sstream >> index;
				sstream.clear();
				_displayPhonebookDataAsList(index);
				_displayPhonebookDataAsList(firstName);
				_displayPhonebookDataAsList(_getContact(i).getLastName());
				_displayPhonebookDataAsList(_getContact(i).getNickname());
				std::cout << std::endl;
			}
		}
		for (int i = 0 ; i < 44 ; i++)
			std::cout << "=";
		std::cout << std::endl;
		indexNb = _retrieveIndexFromUser();
		if (indexNb >= 0)
			_getContact(indexNb).displayContactData();
	}
	return ;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "Destructor of Phonebook called" << std::endl;
	return ;
}