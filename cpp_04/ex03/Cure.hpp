/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:20:11 by plouda            #+#    #+#             */
/*   Updated: 2024/03/26 09:31:53 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& refObj);
		Cure& operator = (const Cure& refObj);
		~Cure();

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};

#endif  // CURE_HPP

