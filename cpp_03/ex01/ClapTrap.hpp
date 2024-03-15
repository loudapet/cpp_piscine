/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:40:07 by plouda            #+#    #+#             */
/*   Updated: 2024/03/15 12:44:23 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;		

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& refObj);
		ClapTrap& operator = (const ClapTrap& refObj);
		~ClapTrap();

		void					setName(const std::string name);
		void					setHp(unsigned int amount);
		void					setEp(unsigned int amount);
		void					setAd(unsigned int amount);
		const std::string&		getName() const;
		int						getHp() const;
		int						getEp() const;
		int						getAd()	const;

		void					attack(const std::string& target);
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);
};

#endif