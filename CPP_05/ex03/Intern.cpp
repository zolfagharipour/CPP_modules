/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:32:37 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 17:41:54 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*	Intern::_makeShrub( const std::string& target )
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_makeRobot( const std::string& target )
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::_makePres( const std::string& target )
{
	return new PresidentialPardonForm(target);
}

Intern::Intern( void )
{
	std::cout << "Intern default constructor." << std::endl;
}
Intern::Intern( const Intern& other )
{
	(void)other;
	std::cout << "Intern copy constructor." << std::endl;
}

Intern& Intern::operator=( const Intern& other )
{
	(void)other;
	return (*this);
}


Intern::~Intern( void )
{
	std::cout << "Intern destructor." << std::endl;
}


AForm*	Intern::makeForm(std::string fName, std::string target)
{
	typedef AForm* (Intern::*FuncPtr)(const std::string& target);
	FuncPtr 		f[3] = {&Intern::_makeShrub, &Intern::_makeRobot, &Intern::_makePres};
	std::string		fTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (fTypes[i] == fName)
		{
			std::cout << "Intern creates " << fName << " form." << std::endl;
			return (this->*f[i])(target);
		}
	}
	std::cerr << "Intern doesnt know how to create " << fName << " form!" << std::endl;
	return NULL;
}