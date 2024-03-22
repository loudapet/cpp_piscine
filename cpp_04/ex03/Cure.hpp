/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:20:11 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 16:30:09 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		// private attributes here

	public:
		Cure();
		Cure(const Cure& refObj);
		Cure& operator = (const Cure& refObj);
		~Cure();

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};

#endif  // CURE_HPP

