/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:05:37 by plouda            #+#    #+#             */
/*   Updated: 2024/04/22 17:36:50 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <utility>

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vect;
		std::vector<unsigned int>	_sortedVect;
		std::deque<unsigned int>	_deque;

		PmergeMe();
		PmergeMe(const PmergeMe& refObj);
		PmergeMe& operator = (const PmergeMe& refObj);

		void	sort(std::vector<unsigned int>&);
		void	sort(std::deque<unsigned int>&) ;

	public:
		PmergeMe(int argc, const char **argv);
		~PmergeMe();
};

#endif  // PMERGEME_HPP
