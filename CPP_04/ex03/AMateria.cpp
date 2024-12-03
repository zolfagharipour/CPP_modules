/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:37:44 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 14:50:29 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria( std::string const & type )
{
	std::cout << "AMateria has been created." << std::endl;
	_type = type;
}

AMateria::AMateria( const AMateria& other )
{
	*this = other;
}

AMateria& AMateria::operator=( const AMateria& other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


AMateria::~AMateria( void )
{
	std::cout << "AMateria has been destroyed." << std::endl;
}



std::string const& AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "Not equipped!" << std::endl;
	(void)target;
}
