/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:04:50 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 12:54:42 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# define CLR1 "\e[38;5;51m"
# define CLR2 "\e[38;5;208m"
# define CLR3 "\e[38;5;213m"
# define CRESET "\e[0m"

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& refObj);
		AAnimal& operator = (const AAnimal& refObj);
		virtual ~AAnimal();

		virtual void		makeSound(void) const = 0;
		const std::string&	getType() const;
		virtual void	brainScanner() const = 0;
};


#endif  // AANIMAL_HPP
