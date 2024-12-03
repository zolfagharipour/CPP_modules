/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:39:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/14 13:37:03 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Ice has been created." << std::endl;
	_name = "ice";
}

Ice::Ice( const Ice& other ) : AMateria("ice")
{
	std::cout << "Ice has been created." << std::endl;
	*this = other;
}

Ice& Ice::operator=( const Ice& other )
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << "Ice has been destroyed." << std::endl;
}

std::string	Ice::getName( void ) const
{
	return (this->_name);
}

AMateria*	Ice::clone( void ) const
{
	AMateria*	ice = new Ice();
	return (ice);
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
