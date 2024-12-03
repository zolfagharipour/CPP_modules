/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:58:23 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:48 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    std::cout << "A WrongCat has been born!" << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "A WrongCat has died!" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Meeooowwaahhahahaahaha..." << std::endl;
}
