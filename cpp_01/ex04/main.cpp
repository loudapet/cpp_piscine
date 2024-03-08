/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:40:15 by plouda            #+#    #+#             */
/*   Updated: 2024/03/08 10:35:15 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	processAndReplace(std::ofstream& ofs, std::string& buffer, 
			std::string toReplace, std::string newString)
{
	std::size_t	position;

	position = buffer.find(toReplace, 0);
	if (position != std::string::npos && toReplace != newString)
	{
		buffer.erase(position, toReplace.size());
		buffer.insert(position, newString);
		processAndReplace(ofs, buffer, toReplace, newString);
	}		
	else
		ofs << buffer;
}

int	main(int argc, const char **argv)
{
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string			buffer;
	std::stringstream	newContent;
	std::string			test;

	if (argc != 4)
		return (EXIT_FAILURE);
	else
	{
		ifs.open(std::string(argv[1]));
		if (!ifs.is_open())
		{
			std::cerr << "Invalid input file" << std::endl;
			return (EXIT_FAILURE);
		}
		ofs.open(std::string(argv[1]) + ".replace");
		if (!ofs.is_open())
		{
			ifs.close();
			std::cerr << "Cannot create output file" << std::endl;
			return (EXIT_FAILURE);
		}
		while (ifs.good())
		{
			std::getline(ifs, buffer, '\n');
			processAndReplace(ofs, buffer, argv[2], argv[3]);
			if (ifs.good())
     		   ofs << std::endl;
		}
		ifs.close();
		ofs.close();
		return (EXIT_SUCCESS);
	}
}