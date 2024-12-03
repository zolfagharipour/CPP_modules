/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:06 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 17:33:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// class AForm;
// class ShruberryCreationForm;

class Intern
{
private:

	AForm*	_makeShrub(  const std::string& target );
	AForm*	_makeRobot( const std::string& target );
	AForm*	_makePres( const std::string& target );
	
public:
	Intern( void );
	Intern( const Intern& other );
	Intern& operator=( const Intern& other );
	~Intern( void );

	AForm*	makeForm(std::string fName, std::string target);
};


