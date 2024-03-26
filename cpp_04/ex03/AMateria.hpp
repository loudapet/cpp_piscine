/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:18:55 by plouda            #+#    #+#             */
/*   Updated: 2024/03/26 09:43:44 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string	_type;
		bool		_inInventory;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& refObj);
		virtual ~AMateria();
		AMateria& 			operator = (const AMateria& refObj);
		std::string const&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
		void				setInInventory(bool value);
		bool				getInInventory() const;
};

#endif  // AMATERIA_HPP
