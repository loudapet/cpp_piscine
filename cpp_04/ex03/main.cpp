/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:51:39 by plouda            #+#    #+#             */
/*   Updated: 2024/03/22 17:06:18 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	/*{
		const AMateria* ice = new Ice();
		const AMateria* cure = new Cure();
		const Ice*	ice2 = new Ice();
		Ice	ice3(*ice2);
		Ice	ice4;
		ice4 = ice3;
		AMateria* newIce;
		
		newIce = ice->clone();
		(void)newIce;

		std::cout << ice->getType() << std::endl;
		std::cout << cure->getType() << std::endl;
		std::cout << ice2->getType() << std::endl;
		std::cout << ice3.getType() << std::endl;
		std::cout << ice4.getType() << std::endl;
		std::cout << newIce->getType() << std::endl;

		delete ice;
		delete ice2;
		delete cure;
		delete newIce;
	} */
	{
		ICharacter *me = new Character("Me");
		ICharacter *enemy = new Character("Enemy");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		me->equip(ice);
		me->equip(cure);
		me->use(0, *enemy);
		me->unequip(0);
		//td::cout << &me->getMateria(0) << std::endl;
		std::cout << &me->getMateria(1) << std::endl;
		//Character::emptyFloor();
		delete me;
		delete enemy;

	}
	return 0;
}