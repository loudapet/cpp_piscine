/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:07:37 by plouda            #+#    #+#             */
/*   Updated: 2024/04/11 11:21:50 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array()
{
	_ptr = NULL;
	_size = 0;
}

template <typename T> Array<T>::Array(unsigned int size)
{
	_ptr = new T[size];
	_size = size;
}

template <typename T> Array<T>::Array(const Array& refObj)
{
	this->_ptr = new T[refObj._size];
	this->_size = refObj._size;
	for (size_t i = 0; i < refObj._size; i++)
		this->_ptr[i] = refObj._ptr[i];
}

template <typename T> Array<T>& Array<T>::operator = (const Array& refObj)
{
	if (this != *refObj)
	{
		this->_ptr = new T[refObj._size];
		this->_size = refObj._size;
		for (size_t i = 0; i < refObj._size; i++)
			this->_ptr[i] = refObj._ptr[i];
	}
	return (*this);
}

template <typename T> T& Array<T>::operator [] (unsigned int index)
{
	if (index < 0 || index >= _size)
		throw (std::exception());
	return (_ptr[index]);
}

template <typename T> Array<T>::~Array()
{
	delete[] this->_ptr;
}

template <typename T>unsigned int	Array<T>::size() const
{
	return (_size);
}
