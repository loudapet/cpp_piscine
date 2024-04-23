/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:05:40 by plouda            #+#    #+#             */
/*   Updated: 2024/04/23 14:14:41 by plouda           ###   ########.fr       */
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
	std::cout << "Creating vector of " + buf + " elements: ";
	start = clock();
	_vect.reserve(argc - 1);
	_sortedVect.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		_vect.push_back(atoi(argv[i]));
	end = clock();
	std::cout << static_cast<double>(end - start) << " microseconds" << std::endl;
	std::cout << "Creating deque of " + buf + " elements: ";
	start = clock();
	for (int i = 1; i < argc; i++)
		_deque.push_back(atoi(argv[i]));
	end = clock();
	std::cout << static_cast<double>(end - start) << " microseconds" << std::endl;
	sort(_vect);
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

static void	highestRecursiveInsertion(std::vector<std::pair<unsigned int, unsigned int> >& vect, unsigned int size)
{
    // Base case 
    if (size <= 1) 
        return; 

    // Recursively sort the first (size - 1) elements
    highestRecursiveInsertion(vect, size - 1);
    std::pair<unsigned int, unsigned int> last = vect[size - 1];
    int j = size - 2;

    // Shift elements greater than last to the right
    while (j >= 0 && vect[j].second > last.second)
    {
        vect[j + 1] = vect[j];
        j--;
    }
    vect[j + 1] = last;
}

unsigned int	jacobNumber(unsigned int index)
{
	if (!index || index == 1)
		return (index);
	return (jacobNumber(index - 1) + 2 * jacobNumber(index - 2));
}

std::vector<unsigned int>	buildJacobsthalSequence(unsigned int size)
{
	std::vector<unsigned int>	sequence;
	unsigned int				jacobIndex = 3;
	
	while (jacobNumber(jacobIndex) < size)
	{
		sequence.push_back(jacobNumber(jacobIndex));
		jacobIndex++;
	}
	sequence.push_back(jacobNumber(jacobIndex)); // extra push for anything larger than the last Jacob number
	return (sequence);
}

std::vector<unsigned int>	generateInsertionSequence(std::vector<unsigned int> jacobsthalSequence)
{
	std::vector<unsigned int>	newSequence;
	unsigned int				prev = 1;
	for (size_t i = 0; i < jacobsthalSequence.size(); i++)
	{
		if (i != 0)
			prev = jacobsthalSequence[i - 1];
		for (size_t j = jacobsthalSequence[i]; j > prev; j--)
			newSequence.push_back(j);
	}
	for (size_t i = 0; i < newSequence.size(); i++)
		newSequence[i] = newSequence[i] - 1; // just to have easier indexing during insertion, because 1st element is actually 1st index by default
	return (newSequence);
}

void	displayPend(std::vector<std::pair<unsigned int,unsigned int> > pairs)
{
	std::cout << "Displaying pend:\t";
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " ";
	std::cout << std::endl;
}

void	displayVect(std::vector<unsigned int> vect)
{
	std::cout << "Displaying vect:\t";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
}

void	insertItems(std::vector<unsigned int>& insertionSequence,
					std::vector<std::pair<unsigned int,unsigned int> >& pend,
					std::vector<unsigned int>& sortedVect)
{
	unsigned int	pendIndex = 1;
	unsigned int	insertionIndex = 0;
	unsigned int	item;
	std::vector<unsigned int>::iterator	insertionPoint;

	displayPend(pend);
	displayVect(insertionSequence);
	while (pendIndex < pend.size())
	{
		while (insertionSequence.size() > insertionIndex 
			&& insertionSequence[insertionIndex] >= pend.size())
			insertionIndex++;
		item = pend[insertionSequence[insertionIndex]].first;
		//std::cout << item << std::endl;
		insertionPoint = std::lower_bound(sortedVect.begin(), sortedVect.end(), item);
		sortedVect.insert(insertionPoint, item);
		pendIndex++;
		insertionIndex++;
	}
	displayVect(sortedVect);
}

void	PmergeMe::sort(std::vector<unsigned int>&)
{
	bool				odd = false;
	int					straggler;
	std::vector<std::pair<unsigned int,unsigned int> >	pairs;
	std::vector<unsigned int>	insertionSequence;

	if (_vect.size() % 2)
	{
		straggler = *_vect.rbegin();
		odd = true;
		_vect.pop_back();
	}
	pairs.reserve(_vect.size() / 2);
	for (std::vector<unsigned int>::iterator it = _vect.begin(); it != _vect.end(); it += 2)
	{
		if (*it <= *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it+1)));
		else
			pairs.push_back(std::make_pair(*(it+1), *it));
	}
	highestRecursiveInsertion(pairs, pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
		_sortedVect.push_back(pairs[i].second);
	_sortedVect.insert(_sortedVect.begin(), pairs[0].first); // insert the first pend element at the beginning of the main chain
	insertionSequence = buildJacobsthalSequence(pairs.size());
	insertionSequence = generateInsertionSequence(insertionSequence);
	insertItems(insertionSequence, pairs, _sortedVect);
	if (odd)
	{
		_sortedVect.insert(std::lower_bound(_sortedVect.begin(), _sortedVect.end(), straggler), straggler);
	}
	std::cout << "Sorted vector:\t\t";
	for (size_t i = 0; i < _sortedVect.size(); i++)
	 	std::cout << _sortedVect[i] << " ";
	std::cout << std::endl;
}
