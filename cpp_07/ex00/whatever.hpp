/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:32:13 by plouda            #+#    #+#             */
/*   Updated: 2024/04/10 12:37:49 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> T max(T x, T y)
{
	return ((x > y) ? x : y);
}

template <typename T> T min(T x, T y)
{
	return ((x < y) ? x : y);
}

template <typename T> void swap(T& x, T& y)
{
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
}

#endif  // WHATEVER_HPP
