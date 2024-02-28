/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:27:48 by plouda            #+#    #+#             */
/*   Updated: 2024/02/28 14:05:01 by plouda           ###   ########.fr       */
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

		void	_displayHeader() const;
		void	_displayPhonebookDataAsList(std::string string) const;
		int		_retrieveIndexFromUser(void) const;
		void	_shiftContactDataQueue();

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	displayContactList(void) const;
};

#endif