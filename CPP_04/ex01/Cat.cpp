/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:57:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/17 12:12:48 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    std::cout << "A Cat has been born!" << std::endl;
    _type = "Cat";
    try{
        this->_brain = new Brain();
    }
    catch(const std::exception& e){
        std::cerr << "allocation failed!" << std::endl;
    }
}

Cat::Cat( const Cat& other ) : Animal()
{
    std::cout << "Cat copy constructor is called." << std::endl;
    *this = other;
}

Cat& Cat::operator=( const Cat& other )
{
    if (this == &other)
        return (*this);
    this->_type = other.getType();
    try{
        this->_brain = new Brain();
    }
    catch(const std::exception& e){
        std::cerr << "allocation failed!" << std::endl;
        return (*this);
    }
    *this->_brain = *other._brain;
    return (*this);
}


Cat::~Cat( void )
{
    delete _brain;
    std::cout << "Cat has died!" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "MeeoOWWww..." << std::endl;
}

void    Cat::steIdea( int i, std::string idea )
{
    _brain->setIdea(i, idea);
}
std::string     Cat::getIdea ( int i )
{
    return(_brain->getIdea(i));
}
