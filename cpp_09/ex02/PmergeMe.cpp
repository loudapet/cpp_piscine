/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:05:40 by plouda            #+#    #+#             */
/*   Updated: 2024/04/24 11:41:45 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(int argc, const char **argv)
{
	std::stringstream	sstr;
	std::string			buf;
	clock_t				start;
	clock_t				end;
	sstr << argc - 1;
	sstr >> buf;
	_vect.reserve(argc - 1);
	_sortedVect.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		_vect.push_back(atoi(argv[i]));
	for (int i = 1; i < argc; i++)
		_deque.push_back(atoi(argv[i]));
	std::cout << "Before: " << _vect << std::endl;

	start = clock();
	_sort(_vect);
	end = clock();
	std::cout << "Time to process a range of " + buf + " elements with std::vector : ";
	std::cout << static_cast<double>(end - start) / 1000. << " ms" << std::endl;

	start = clock();
	_sort(_deque);
	end = clock();
	std::cout << "Time to process a range of " + buf + " elements with std::deque : ";
	std::cout << static_cast<double>(end - start) / 1000. << " ms" << std::endl;
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& refObj)
{
	*this = refObj;
}

PmergeMe& PmergeMe::operator = (const PmergeMe& refObj)
{
	if (this != &refObj)
		return (*this);
	return (*this);
}

PmergeMe::~PmergeMe()
{
	return ;
}

unsigned int	PmergeMe::_jacobNumber(unsigned int index)
{
	if (!index || index == 1)
		return (index);
	return (_jacobNumber(index - 1) + 2 * _jacobNumber(index - 2));
}

void	PmergeMe::_sort(deque_uint_t&)
{
	if (_deque.size() == 1)
		return ;
	bool				odd = false;
	int					straggler;
	deque_uint_pair_t	pairs;
	deque_uint_t		insertionSequence;

	if (_deque.size() % 2)
	{
		straggler = *_deque.rbegin();
		odd = true;
		_deque.pop_back();
	}
	for (deque_uint_t::iterator it = _deque.begin(); it != _deque.end(); it += 2)
	{
		if (*it <= *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it+1)));
		else
			pairs.push_back(std::make_pair(*(it+1), *it));
	}
	_sortPairsByHighest(pairs, pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
		_sortedDeque.push_back(pairs[i].second);
	_sortedDeque.insert(_sortedDeque.begin(), pairs[0].first); // insert the first pend element at the beginning of the main chain
	insertionSequence = _buildJacobsthalSequence<deque_uint_t>(pairs.size());
	insertionSequence = _generateInsertionSequence(insertionSequence);
	_insertItems(insertionSequence, pairs, _sortedDeque);
	if (odd)
		_sortedDeque.insert(std::lower_bound(_sortedDeque.begin(), _sortedDeque.end(), straggler), straggler);
}

void	PmergeMe::_sort(vect_uint_t&)
{
	if (_vect.size() == 1)
	{
		std::cout << "After:  " << _vect.front() << std::endl;
		return ;
	}
	bool				odd = false;
	int					straggler;
	vect_uint_pair_t	pairs;
	vect_uint_t			insertionSequence;

	if (_vect.size() % 2)
	{
		straggler = *_vect.rbegin();
		odd = true;
		_vect.pop_back();
	}
	pairs.reserve(_vect.size() / 2);
	for (vect_uint_t::iterator it = _vect.begin(); it != _vect.end(); it += 2)
	{
		if (*it <= *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it+1)));
		else
			pairs.push_back(std::make_pair(*(it+1), *it));
	}
	_sortPairsByHighest(pairs, pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
		_sortedVect.push_back(pairs[i].second);
	_sortedVect.insert(_sortedVect.begin(), pairs[0].first); // insert the first pend element at the beginning of the main chain
	insertionSequence = _buildJacobsthalSequence<vect_uint_t>(pairs.size());
	insertionSequence = _generateInsertionSequence(insertionSequence);
	_insertItems(insertionSequence, pairs, _sortedVect);
	if (odd)
		_sortedVect.insert(std::lower_bound(_sortedVect.begin(), _sortedVect.end(), straggler), straggler);
	std::cout << "After:  " << _sortedVect << std::endl;
}

void		PmergeMe::processNumbers(int argc, const char **argv)
{
	if (argc < 2)
		throw (std::runtime_error("Error: expected at least one number as argument"));
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw (std::invalid_argument("Error: only positive integers allowed as arguments"));
			if (j > 10)
				throw (std::invalid_argument("Error: number too big"));
		}
		if (std::strtol(argv[i], NULL, 10) > UINT_MAX)
			throw (std::invalid_argument("Error: number too big"));
	}
}

std::ostream &operator<<(std::ostream &os, vect_uint_t &vec)
{
	for (vect_uint_t::iterator it = vec.begin(); it != vec.end(); it++)
		os << " " << *it;
	return os;
}

std::ostream &operator<<(std::ostream &os, deque_uint_t &deq)
{
	for (deque_uint_t::iterator it = deq.begin(); it != deq.end(); it++)
		os << " " << *it;
	return os;
}