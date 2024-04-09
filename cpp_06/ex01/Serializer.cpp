/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:08:40 by plouda            #+#    #+#             */
/*   Updated: 2024/04/09 11:34:56 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer& refObj)
{
	*this = refObj;
}

Serializer& Serializer::operator = (const Serializer& refObj)
{
	(void)refObj;
	return (*this);
}

Serializer::~Serializer()
{
	return ;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
