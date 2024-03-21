/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:38:22 by plouda            #+#    #+#             */
/*   Updated: 2024/03/21 09:50:22 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CPP
#define BRAIN_CPP
#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& refObj);
		Brain& operator = (const Brain& refObj);
		~Brain();
};

#endif  // BRAIN_CPP
