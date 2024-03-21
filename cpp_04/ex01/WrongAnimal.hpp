/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:10:03 by plouda            #+#    #+#             */
/*   Updated: 2024/03/20 12:51:16 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>
# define CLR1 "\e[38;5;51m"
# define CLR2 "\e[38;5;208m"
# define CLR3 "\e[38;5;213m"
# define CRESET "\e[0m"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& refObj);
		WrongAnimal& operator = (const WrongAnimal& refObj);
		~WrongAnimal();

		void		makeSound(void) const;
		const std::string&	getType() const;
};

#endif  // WRONGANIMAL_HPP

