/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:22:55 by plouda            #+#    #+#             */
/*   Updated: 2024/03/29 10:29:41 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& refObj);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& refObj);
		~RobotomyRequestForm();

		void		execute(Bureaucrat const & executor) const;
};

#endif  // ROBOTOMYREQUESTFORM_HPP