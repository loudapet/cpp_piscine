/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:26 by plouda            #+#    #+#             */
/*   Updated: 2024/03/29 10:38:11 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& refObj);
		PresidentialPardonForm& operator = (const PresidentialPardonForm& refObj);
		~PresidentialPardonForm();

		void		execute(Bureaucrat const & executor) const;
};

#endif  // PRESIDENTIALPARDONFORM_HPP