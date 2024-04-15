/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:32:27 by plouda            #+#    #+#             */
/*   Updated: 2024/04/15 12:04:42 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <climits>

class Span
{
	private:
		std::multiset<int>	_set;
		unsigned int				_maxSize;

		Span();

	public:
		Span(unsigned int limit);
		Span(const Span& refObj);
		Span& operator = (const Span& refObj);
		~Span();

		void	addNumber(int nb);
		void	fillWithNumbers(int rangeFrom, int rangeTo, unsigned int span);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printSet() const;
};

#endif  // SPAN_HPP
