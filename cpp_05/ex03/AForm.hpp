/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:51:18 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 14:54:16 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& refObj);
		AForm& operator = (const AForm& refObj);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSigned() const;
		const int&			getGradeToSign() const;
		const int&			getGradeToExec() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void				checkIfExecutable(Bureaucrat const & executor) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::invalid_argument
		{
			public:
				GradeTooLowException();
				const char*		what() const throw();
		};
		class GradeTooHighException : public std::invalid_argument
		{
			public:
				GradeTooHighException();
				const char*		what() const throw();
		};
		class NotSignedException : public std::logic_error
		{
			public:
				NotSignedException();
				const char*		what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &outputStream, const AForm& form);

#endif  // AFORM_HPP
