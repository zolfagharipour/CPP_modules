/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:58:03 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 16:04:23 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    Animal::_type = "Dog";
    std::cout << "A Dog has been born!" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "A Dog has died!" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Wuff Wuff..." << std::endl;
}
