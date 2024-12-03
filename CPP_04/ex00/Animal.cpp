/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:57:46 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 16:00:33 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal( void ) : _type("NA")
{
    std::cout << "An Animal has been born!" << std::endl;
}

Animal::Animal( const Animal& other )
{
    *this = other;
}

Animal& Animal::operator=( const Animal& other )
{
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "An Animal has died!" << std::endl;
}



std::string     Animal::getType( void ) const
{
    return(this->_type);
}


void    Animal::makeSound( void ) const
{
    std::cout << "Unrecognizable Animal sounds." << std::endl;
}
