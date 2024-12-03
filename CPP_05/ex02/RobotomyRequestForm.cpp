/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:37:38 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 12:41:55 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Robot", 72, 45), _target("default")
{
	std::cout << "Robot default constructor." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robot", 72, 45), _target(target)
{
	std::cout << "Robot constructor." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm("Robot", 72, 45), _target(other._target)
{
	std::cout << "Robot copy constructor." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "Robot destructor." << std::endl;
}

void	RobotomyRequestForm::action( void ) const
{
	std::cout << "Brrrr... Bzzz..." << std::endl;
	std::srand(std::time(0));
	int		rand = std::rand();
	if (rand % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << ": robotomy failed." << std::endl;
}