/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:08:47 by plouda            #+#    #+#             */
/*   Updated: 2024/04/09 11:59:57 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
# include <stdint.h>


struct  Data
{
	int		a;
	double	b;
	char	c;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& refObj);
		Serializer& operator = (const Serializer& refObj);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP
