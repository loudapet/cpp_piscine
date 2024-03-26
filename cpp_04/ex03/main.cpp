/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:51:39 by plouda            #+#    #+#             */
/*   Updated: 2024/03/26 13:55:58 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <unistd.h>

int	main()
{
	{
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
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	{
		ICharacter *me = new Character("Me");
		ICharacter *enemy = new Character("Enemy");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		me->equip(ice);
		me->equip(cure);
		me->equip(cure);
		me->equip(ice);
		me->equip(cure);

		me->use(0, *enemy);
		me->unequip(0);
		me->unequip(1);
		//std::cout << me->getMateria(0) << std::endl;
		//std::cout << me->getMateria(1) << std::endl;
		enemy->equip(ice);
		me->equip(cure);
		enemy->use(0, *me);
		me->unequip(0);
		Character::emptyFloor();
		delete me;
		delete enemy;
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("Moonshine");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("Bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete me;
		delete bob;
		delete src;
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	{
		ICharacter *me = new Character("Me");
		ICharacter *enemy = new Character("Enemy");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria* ice = src->createMateria("ice");
		AMateria* cure = src->createMateria("cure");
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(cure);
		src->learnMateria(ice);
		AMateria* tmp;

		me->equip(ice);
		enemy->equip(ice);
		enemy->equip(cure);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;

		me->use(0, *enemy);
		me->unequip(0);
		me->unequip(1);
		
		enemy->equip(ice);
		me->equip(cure);
		enemy->use(0, *me);
		me->unequip(0);
		
		Character::emptyFloor();
		delete me;
		delete enemy;
		delete src;
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	{
		for (int i = 0 ; i < 102 ; i++)
		{
			ICharacter *me = new Character("Chump");
			AMateria* cure = new Cure();
			me->equip(cure);
			me->unequip(0);
			delete me;
		}
		Character::emptyFloor();
	}
	return 0;
}