/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:05:37 by plouda            #+#    #+#             */
/*   Updated: 2024/04/24 11:29:44 by plouda           ###   ########.fr       */
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
#include <exception>

typedef std::vector< std::pair<unsigned int,unsigned int> > vect_uint_pair_t;
typedef std::deque< std::pair<unsigned int,unsigned int> > deque_uint_pair_t;
typedef std::vector<unsigned int> vect_uint_t;
typedef std::deque<unsigned int> deque_uint_t;

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vect;
		std::vector<unsigned int>	_sortedVect;
		std::deque<unsigned int>	_deque;
		std::deque<unsigned int>	_sortedDeque;

		PmergeMe();
		PmergeMe(const PmergeMe& refObj);
		PmergeMe& operator = (const PmergeMe& refObj);

		template <typename Container>
		void		_sortPairsByHighest(Container& cont, unsigned int size);
		template <typename Container>
		Container	_buildJacobsthalSequence(unsigned int size);
		template <typename Container>
		Container	_generateInsertionSequence(Container jacobsthalSequence);
		template <typename Container, typename PairContainer>
		void		_insertItems(Container& insertionSequence,
								PairContainer& pend,
								Container& sortedVect);

		unsigned int	_jacobNumber(unsigned int index);
		void			_sort(std::vector<unsigned int>&);
		void			_sort(std::deque<unsigned int>&);

	public:
		PmergeMe(int argc, const char **argv);
		~PmergeMe();
	
		static void		processNumbers(int argc, const char **argv);
};
#include "PmergeMe.tpp"

std::ostream &operator<<(std::ostream &os, std::vector<unsigned int> &vec);
std::ostream &operator<<(std::ostream &os, std::deque<unsigned int> &deq);

#endif  // PMERGEME_HPP
