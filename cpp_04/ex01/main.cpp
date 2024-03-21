/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:05:08 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 12:14:18 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal* cat1 = new Cat();
		const Animal* cat2 = new Cat();
		const Cat*	cat3 = new Cat();
		Cat	cat4(*cat3);
		Cat	cat5;
		cat5 = *cat3;
		const Animal* dog1 = new Dog();
		const Animal* dog2 = new Dog();
		const Dog*	dog3 = new Dog();
		Dog	dog4(*dog3);
		Dog	dog5;
		dog5 = *dog3;
		std::cout << "Scanning brains!" << std::endl;
		cat1->brainScanner();
		cat2->brainScanner();
		cat3->brainScanner();
		cat4.brainScanner();
		cat5.brainScanner();
		dog1->brainScanner();
		dog2->brainScanner();
		dog3->brainScanner();
		dog4.brainScanner();
		dog5.brainScanner();
		delete cat1;
		delete cat2;
		delete cat3;
		delete dog1;
		delete dog2;
		delete dog3;
	}
	{
		std::cout << "//////////////////////////////////" << std::endl;
		int	i = 0;
		const Animal*	array[10];
		while (i < 5)
			array[i++] = new Cat();
		while (i < 10)
			array[i++] = new Dog();
		for (--i ; i >= 0 ; --i )
			array[i]->brainScanner();
		for (i++ ; i < 10 ; ++i)
			delete array[i];
	}
	{
		std::cout << "//////////////////////////////////" << std::endl;
		Dog basic;
		{
			Dog tmp = basic;
			tmp.brainScanner();
		}
		basic.brainScanner();
	}
	return 0;
}