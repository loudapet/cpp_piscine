/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:27:48 by plouda            #+#    #+#             */
/*   Updated: 2024/02/26 16:44:28 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "general.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contactList[8];

		//Contact	*_getContact(int index);
		Contact	_getContact(int index) const;
		void	_displayHeader() const;
		void	_displayPhonebookDataAsList(std::string string) const;
		int		_retrieveIndexFromUser(void) const;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(int *index);
		void	displayContactList(void) const;
};

#endif