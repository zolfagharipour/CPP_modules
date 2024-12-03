/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:58:03 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/17 12:13:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    std::cout << "A Dog has been born!" << std::endl;
    Animal::_type = "Dog";
    try{
        this->_brain = new Brain();
    }
    catch(const std::exception& e){
        std::cerr << "allocation failed!" << std::endl;
    }
}

Dog::Dog( const Dog& other ) : Animal()
{
    std::cout << "Dog copy constructor is called." << std::endl;
    *this = other;
}

Dog& Dog::operator=( const Dog& other )
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


Dog::~Dog( void )
{
    delete _brain;
    std::cout << "A Dog has died!" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Wuff Wuff..." << std::endl;
}

void    Dog::steIdea( int i, std::string idea )
{
    _brain->setIdea(i, idea);
}
std::string     Dog::getIdea ( int i )
{
    return(_brain->getIdea(i));
}

