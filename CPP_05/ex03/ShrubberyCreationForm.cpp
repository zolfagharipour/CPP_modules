/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:07 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 14:43:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "Schrub", 145, 137), _target("Default")
{
	std::cout << "Shrubbery default constructor." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "Schrub", 145, 137), _target(target)
{
	std::cout << "Shrubbery constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm("Shrub", 145, 137), _target(other._target)
{
	std::cout << "Shrubbery copy constructor." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Shrubbery destructor." << std::endl;
}


void	ShrubberyCreationForm::action( void ) const
{
	std::string tree =
        "         ccee88oo\n"
        "  C8O8O8Q8PoOb o8oo\n"
        " dOB69QO8PdUOpugoO9bD\n"
        "CgggbU8OU qOp qOdoUOdcb\n"
        "    6OuU  /p u gcoUodpP\n"
        "      \\\\//  /douUP\n"
        "        \\\\////\n"
        "         |||/\\\n"
        "         |||\\/\n"
        "         |||||\n"
        "   .....//||||\\....\n";
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream oFile;
	oFile.open(fileName.c_str(), std::ios::app);
	if (!oFile)
		std::cerr << "Cant open the file" << std::endl;
	else
	{
		oFile << tree << std::endl;
		oFile.close();
	}
}