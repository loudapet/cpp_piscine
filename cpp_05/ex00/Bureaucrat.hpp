/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:38:44 by plouda            #+#    #+#             */
/*   Updated: 2024/03/27 15:13:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# define YEL "\e[38;5;214m"
# define GREY "\e[38;5;244m"
# define CRESET "\e[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& refObj);
		Bureaucrat& operator = (const Bureaucrat& refObj);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				gradeUp();
		void				gradeUp(int value);
		void				gradeDown();
		void				gradeDown(int value);
		Bureaucrat&			operator++();
		Bureaucrat			operator++(int);
		Bureaucrat&			operator--();
		Bureaucrat			operator--(int);

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

std::ostream&	operator<<(std::ostream &outputStream, const Bureaucrat& bureaucrat);

#endif  // BUREAUCRAT_HPP
