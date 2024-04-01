/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:43:06 by plouda            #+#    #+#             */
/*   Updated: 2024/03/28 15:23:21 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137), _target("Not specified")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& refObj) : 
	AForm("ShrubberyCreationForm", 145, 137)
{
	_target = refObj._target;
	*this = refObj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& refObj)
{
	if (this != &refObj)
		this->_target = refObj._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::checkIfExecutable(executor);
	std::ofstream		ofs;
	ofs.open(_target + "_shrubbery");
	if (!ofs.is_open())
		throw (outfileNotOpenException());
	ofs << "            ,@@@@@@@,                 " << std::endl;
	ofs << "    ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl;
	ofs << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl;
	ofs << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl;
	ofs << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl;
	ofs << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl;
	ofs << "`&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
	ofs << "    |o|        | |         | |        " << std::endl;
	ofs << "    |.|        | |         | |        " << std::endl;
	ofs << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	ofs.close();
}

ShrubberyCreationForm::outfileNotOpenException::outfileNotOpenException() :
	std::runtime_error("")
{
	return ;
}

const char* ShrubberyCreationForm::outfileNotOpenException::what() const throw()
{
	return ("Could not open output file");
}


