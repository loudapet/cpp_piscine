/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:32:29 by plouda            #+#    #+#             */
/*   Updated: 2024/04/09 12:23:47 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>


// https://stackoverflow.com/questions/18544849/how-to-use-reinterpret-cast-in-c
// https://stackoverflow.com/questions/68576099/is-reinterpret-cast-actually-good-for-anything
int	main(void)
{
	Data data;
	data.a = 1;
	data.b = 2;
	data.c = 'c';

	std::cout << std::endl;
	std::cout << data.a << " " << data.b << " " << data.c << std::endl;
	std::cout <<  "Serializing..."  << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Deserializing..." << std::endl;
	Data* serialized = Serializer::deserialize(raw);
	std::cout << "Original:\t" << &data << std::endl; 
	std::cout << "Serialized:\t" << serialized << std::endl;
	std::cout << serialized->a << " " << serialized->b << " " << serialized->c << std::endl;
	std::cout << std::endl;
}