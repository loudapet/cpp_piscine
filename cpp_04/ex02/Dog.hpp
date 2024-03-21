/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:44 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 12:51:55 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog& refObj);
		Dog& operator = (const Dog& refObj);
		~Dog();

		void	makeSound() const;
		void	brainScanner() const;
};

#endif  // DOG_HPP
