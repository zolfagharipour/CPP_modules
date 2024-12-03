/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:38:38 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 14:30:20 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Pres", 25, 5), _target("default")
{
	std::cout << "President default constructor." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Pres", 25, 5), _target(target)
{
	std::cout << "President constructor." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm("Pres", 25, 5), _target(other._target)
{
	std::cout << "President copy constructor." << std::endl;	
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "President destructor." << std::endl;
}

void	PresidentialPardonForm::action( void ) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}