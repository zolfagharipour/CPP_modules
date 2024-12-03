/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:04:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:08 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("NA")
{
    std::cout << "A WrongAnimal has been born!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
    *this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
    if (this == &other)
        return(*this);
    this->_type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "A WrongAnimal has died!" << std::endl;
}


std::string     WrongAnimal::getType( void )const
{
    return (this->_type);
}


void    WrongAnimal::makeSound( void )const
{
    std::cout << "Unbearable beast sounds..." << std::endl;
}
