/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:10 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 14:39:23 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "Cure has been created." << std::endl;
	_name = "cure";
}

Cure::Cure( const Cure& other ) : AMateria("cure")
{
	std::cout << "Cure has been created." << std::endl;
	*this = other;
}

Cure& Cure::operator=( const Cure& other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);	
}

Cure::~Cure()
{
	std::cout << "Cure has been destroyed." << std::endl;
}


std::string	Cure::getName( void ) const
{
	return (this->_name);
}

AMateria*	Cure::clone( void ) const
{
	AMateria*	ice = new Cure();
	return (ice);
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}