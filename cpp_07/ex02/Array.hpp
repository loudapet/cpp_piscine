/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:06:51 by plouda            #+#    #+#             */
/*   Updated: 2024/04/11 10:55:16 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T> class Array
{
	private:
		T*				_ptr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int size);
		Array(const Array& refObj);
		Array& operator = (const Array& refObj);
		T& operator [] (unsigned int index);
		~Array();

		unsigned int	size() const;
};
#include "Array.tpp"

#endif  // ARRAY_HPP
