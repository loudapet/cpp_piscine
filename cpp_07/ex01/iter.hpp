/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:32:13 by plouda            #+#    #+#             */
/*   Updated: 2024/04/10 13:30:45 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <string>
#include <iostream>

template <typename T> void iter(T* addr, size_t size, void(*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		(f)(addr[i]);
}

template <typename T> void decrement(T& x)
{
	x--;
	std::cout << x << std::endl;
}

#endif  // ITER_HPP
