/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:43:38 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 15:16:20 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& refObj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& refObj);
		~ShrubberyCreationForm();

		void		execute(Bureaucrat const & executor) const;

		class outfileNotOpenException : public std::runtime_error
		{
			public:
				outfileNotOpenException();
				const char*		what() const throw();
		};
};

#endif  // SHRUBBERYCREATIONFORM_HPP
