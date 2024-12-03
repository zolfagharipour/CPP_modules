/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:57:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 16:04:16 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    _type = "Cat";
    std::cout << "A Cat has been born!" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat has died!" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "MeeoOWWww..." << std::endl;
}
