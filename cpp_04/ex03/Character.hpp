/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:55:18 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 16:45:49 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];

		static AMateria*	_floor[100];

	public:
		Character();
		Character(std::string name);
		Character(const Character& refObj);
		Character& operator = (const Character& refObj);
		~Character();

		std::string	const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		const std::string& getMateria(int idx) const;
		
		static void			emptyFloor();
};

#endif  // CHARACTER_HPP
