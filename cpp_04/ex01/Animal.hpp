/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:04:50 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 10:43:06 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# define CLR1 "\e[38;5;51m"
# define CLR2 "\e[38;5;208m"
# define CLR3 "\e[38;5;213m"
# define CRESET "\e[0m"

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& refObj);
		Animal& operator = (const Animal& refObj);
		virtual ~Animal();

		virtual void		makeSound(void) const;
		const std::string&	getType() const;
		virtual void	brainScanner() const;
};


#endif  // ANIMAL_HPP
