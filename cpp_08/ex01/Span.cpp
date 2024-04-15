/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:35:52 by plouda            #+#    #+#             */
/*   Updated: 2024/04/15 12:33:30 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <unistd.h>

Span::Span()
{
	return ;
}

Span::Span(unsigned int limit)
{
	_maxSize = limit;
	return ;
}

Span::Span(const Span& refObj)
{
	*this = refObj;
}

Span& Span::operator = (const Span& refObj)
{
	if (this != &refObj)
	{
		_set = refObj._set;
		_maxSize = refObj._maxSize;
	}
	return (*this);
}

Span::~Span()
{
	return ;
}

void	Span::addNumber(int nb)
{
	if (_set.size() >= _maxSize)
		throw(std::runtime_error("Container cannot fit in more numbers"));
	_set.insert(nb);
}

int	Span::shortestSpan() const
{
	if (_set.empty() || _set.size() <= 1)
		throw(std::runtime_error("Cannot determine span"));
	if (std::adjacent_find(_set.begin(), _set.end()) != _set.end())
		return (0);
		
	int	minSpan = INT_MAX;
	std::multiset<int>::iterator			iter1;
	std::multiset<int>::iterator			iter2;
	std::multiset<int>::reverse_iterator	lastElement;
	lastElement = _set.rbegin();

	iter1 = _set.begin();
	while (*iter1 != *lastElement)
	{
		iter2 = _set.upper_bound(*iter1);
		while (iter2 != _set.end())
		{
			if (abs(*iter1 - *iter2) < minSpan)
				minSpan = abs(*iter1 - *iter2);
			iter2 = _set.upper_bound(*iter2);
		}
		iter1++;
	}
	return (minSpan);
}

int	Span::longestSpan() const
{
	if (_set.empty() || _set.size() <= 1)
		throw(std::runtime_error("Cannot determine span"));
	return (abs(*(_set.rbegin()) - *(_set.begin())));
}

void	Span::printSet() const
{
	for (std::multiset<int>::iterator it = _set.begin() ; it != _set.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	Span::fillWithNumbers(int rangeFrom, int rangeTo, unsigned int span)
{
	if (!span)
		throw(std::runtime_error("Span must be a strictly positive number"));
	if ((abs(rangeFrom - rangeTo) / span) + _set.size() >= _maxSize)
		throw(std::runtime_error("Cannot fit in desired range of numbers"));
	if (rangeFrom > rangeTo)
		std::swap(rangeFrom, rangeTo);
	for (int i = rangeFrom; i <= rangeTo; i += span)
		addNumber(i);
}
