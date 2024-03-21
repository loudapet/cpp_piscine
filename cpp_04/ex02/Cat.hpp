/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:22 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 12:51:42 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(const Cat& refObj);
		Cat& operator = (const Cat& refObj);
		~Cat();

		void	makeSound() const;
		void	brainScanner() const;
};

#endif  // CAT_HPP
