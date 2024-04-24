/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:40:00 by plouda            #+#    #+#             */
/*   Updated: 2024/04/24 09:56:12 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void	PmergeMe::_sortPairsByHighest(Container& cont, unsigned int size)
{
	if (size <= 1) 
		return; 
	// Recursively sort the first (size - 1) elements
	_sortPairsByHighest(cont, size - 1);
	std::pair<unsigned int, unsigned int> last = cont[size - 1];
	int j = size - 2;
	// Shift elements greater than last to the right
	while (j >= 0 && cont[j].second > last.second)
	{
		cont[j + 1] = cont[j];
		j--;
	}
	cont[j + 1] = last;
}

template <typename Container>
Container	PmergeMe::_buildJacobsthalSequence(unsigned int size)
{
	Container		sequence;
	unsigned int	jacobIndex = 3;
	
	while (_jacobNumber(jacobIndex) < size)
	{
		sequence.push_back(_jacobNumber(jacobIndex));
		jacobIndex++;
	}
	sequence.push_back(_jacobNumber(jacobIndex)); // extra push for anything larger than the last Jacob number
	return (sequence);
}

template <typename Container>
Container	PmergeMe::_generateInsertionSequence(Container jacobsthalSequence)
{
	Container		newSequence;
	unsigned int	prev = 1;
	for (size_t i = 0; i < jacobsthalSequence.size(); i++)
	{
		if (i != 0)
			prev = jacobsthalSequence[i - 1];
		for (size_t j = jacobsthalSequence[i]; j > prev; j--)
			newSequence.push_back(j - 1); // -1 because it is used as index
	}
	return (newSequence);
}

template <typename Container, typename PairContainer>
void	PmergeMe::_insertItems(Container& insertionSequence,
					PairContainer& pend,
					Container& sortedContainer)
{
	unsigned int					pendIndex = 1; // the first element had already been inserted
	unsigned int					insertionIndex = 0;
	unsigned int					item;
	typename Container::iterator	insertionPoint;

	while (pendIndex < pend.size())
	{
		while (insertionSequence.size() > insertionIndex 
			&& insertionSequence[insertionIndex] >= pend.size())
			insertionIndex++;
		item = pend[insertionSequence[insertionIndex]].first;
		insertionPoint = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), item);
		sortedContainer.insert(insertionPoint, item);
		pendIndex++;
		insertionIndex++;
	}
}