/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:19:41 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 14:33:46 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& refObj);
		Ice& operator = (const Ice& refObj);
		~Ice();

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};

#endif  // ICE_HPP
