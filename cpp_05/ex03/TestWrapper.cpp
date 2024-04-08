/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestWrapper.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:07:04 by plouda            #+#    #+#             */
/*   Updated: 2024/04/08 08:52:01 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestWrapper.hpp"

TestWrapper::TestWrapper() : _shrubbery(NULL), _robotomy(NULL), _pardon(NULL),
	_high(Bureaucrat("High", 3)), _low(Bureaucrat("Low", 148))
{
	Intern	intern;
	_shrubbery = intern.makeForm("shrubbery creation", "Default");
	_robotomy = intern.makeForm("robotomy request", "defaultRobot");
	_pardon = intern.makeForm("presidential pardon", "defaultPardon");
	return ;
}

TestWrapper::TestWrapper(int testNb) : _shrubbery(NULL), _robotomy(NULL), _pardon(NULL),
	_high(Bureaucrat("High", 3)), _low(Bureaucrat("Low", 148))
{
	Intern	intern;
	std::stringstream sstream;
	sstream << "home_" << testNb;
	_shrubbery = intern.makeForm("shrubbery creation", sstream.str());
	sstream.str("");
	sstream << "almostRobot_" << testNb;
	_robotomy = intern.makeForm("robotomy request", sstream.str());
	sstream.str("");
	sstream << "Harry Potter " << testNb;
	_pardon = intern.makeForm("presidential pardon", sstream.str());
	sstream.str("");
}

TestWrapper::TestWrapper(Bureaucrat high, Bureaucrat low, int testNb) : _shrubbery(NULL),
	 _robotomy(NULL), _pardon(NULL), _high(high), _low(low)
{
	Intern	intern;
	std::stringstream sstream;
	sstream << "home_" << testNb;
	_shrubbery = intern.makeForm("shrubbery creation", sstream.str());
	sstream.str("");
	sstream << "almostRobot " << testNb;
	_robotomy = intern.makeForm("robotomy request", sstream.str());
	sstream.str("");
	sstream << "Harry Potter " << testNb;
	_pardon = intern.makeForm("presidential pardon", sstream.str());
	sstream.str("");
}

// deep copy
TestWrapper::TestWrapper(const TestWrapper& refObj)
{
	_shrubbery = new ShrubberyCreationForm(refObj._shrubbery->getName());
	_robotomy = new RobotomyRequestForm(refObj._robotomy->getName());
	_pardon = new PresidentialPardonForm(refObj._pardon->getName());
	_high = Bureaucrat(refObj._high.getName(), refObj._high.getGrade());
	_low = Bureaucrat(refObj._low.getName(), refObj._low.getGrade());
}

// shallow copy
TestWrapper& TestWrapper::operator = (const TestWrapper& refObj)
{
	if (this != &refObj)
	{
		_shrubbery = refObj._shrubbery;
		_robotomy = refObj._robotomy;
		_pardon = refObj._pardon;
		_high = refObj._high;
		_low = refObj._low;
	}
	return (*this);
}

TestWrapper::~TestWrapper()
{
	std::cout << "Test destructor called" << std::endl;
	delete _shrubbery;
	delete _robotomy;
	delete _pardon;
	return ;
}

Bureaucrat	TestWrapper::getHigh() const
{
	return (_high);
}

Bureaucrat	TestWrapper::getLow() const
{
	return (_low);
}

AForm*	TestWrapper::getShrubbery() const
{
	return (_shrubbery);
}

AForm*	TestWrapper::getRobotomy() const
{
	return (_robotomy);
}

AForm*	TestWrapper::getPardon() const
{
	return (_pardon);
}

void	TestWrapper::testBasic(const std::string test)
{
	(void)test;
	std::cout << *this->getShrubbery() << std::endl;
	std::cout << *this->getRobotomy() << std::endl;
	std::cout << *this->getPardon() << std::endl;
}
void	TestWrapper::testShrubbery(const std::string test)
{
	std::cout << *this->getShrubbery() << std::endl;
	if (test.find("low grade") != std::string::npos)
	{
		this->getHigh().signForm(*this->getShrubbery());
		this->getLow().executeForm(*this->getShrubbery());
	}
	else if (test.find("not signed") != std::string::npos)
	{
		this->getLow().executeForm(*this->getShrubbery());
	}
	else
	{
		this->getHigh().signForm(*this->getShrubbery());
		this->getHigh().executeForm(*this->getShrubbery());
	}
}
void	TestWrapper::testRobotomy(const std::string test)
{
	std::cout << *this->getRobotomy() << std::endl;
	if (test.find("low grade") != std::string::npos)
	{
		this->getHigh().signForm(*this->getRobotomy());
		this->getLow().executeForm(*this->getRobotomy());
	}
	else if (test.find("not signed") != std::string::npos)
	{
		this->getLow().executeForm(*this->getRobotomy());
	}
	else
	{
		this->getHigh().signForm(*this->getRobotomy());
		this->getHigh().executeForm(*this->getRobotomy());
	}
}
void	TestWrapper::testPardon(const std::string test)
{
	std::cout << *this->getPardon() << std::endl;
	if (test.find("low grade") != std::string::npos)
	{
		this->getHigh().signForm(*this->getPardon());
		this->getLow().executeForm(*this->getPardon());
	}
	else if (test.find("not signed") != std::string::npos)
	{
		this->getLow().executeForm(*this->getPardon());
	}
	else
	{
		this->getHigh().signForm(*this->getPardon());
		this->getHigh().executeForm(*this->getPardon());
	}
}

void	TestWrapper::test(const std::string test)
{
	std::string		testArray[4] = {"Basic", "Shrubbery", "Robotomy", "Pardon"};
	testForm		fptrArray[4] = {&TestWrapper::testBasic, &TestWrapper::testShrubbery,
									&TestWrapper::testRobotomy, &TestWrapper::testPardon};
	for (int i = 0 ; i < 4 ; i++)
	{
		if (test.find(testArray[i]) != std::string::npos)
		{
			switch (i)
			{
				case 0:
					(this->*fptrArray[0])(test);
					break;
				case 1:
					(this->*fptrArray[1])(test);
					break;
				case 2:
					(this->*fptrArray[2])(test);
					break;
				case 3:
					(this->*fptrArray[3])(test);
					break;
			}
			break ;
		}
	}
}

