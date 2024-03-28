/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:51:18 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 10:26:27 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& refObj);
		Form& operator = (const Form& refObj);
		~Form();

		const std::string&	getName() const;
		bool				getSigned() const;
		const int&			getGradeToSign() const;
		const int&			getGradeToExec() const;
		void			beSigned(Bureaucrat& bureaucrat);


		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException();
				const char*		what() const throw();
		};
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException();
				const char*		what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &outputStream, const Form& form);

#endif  // FORM_HPP
