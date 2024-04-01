/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:12:30 by plouda            #+#    #+#             */
/*   Updated: 2024/04/01 12:18:43 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm*	newShrubberyCreationForm(const std::string target);
		AForm*	newRobotomyRequestForm(const std::string target);
		AForm*	newPresidentialPardonForm(const std::string target);

	public:
		Intern();
		Intern(const Intern& refObj);
		Intern& operator = (const Intern& refObj);
		~Intern();

		AForm*	makeForm(const std::string formName, const std::string formTarget);

		class UnknownNameException : public std::invalid_argument
		{
			public:
				UnknownNameException();
				const char*	what() const throw();
		};
};

typedef AForm*(Intern::*createForm)(const std::string);

#endif  // INTERN_HPP
