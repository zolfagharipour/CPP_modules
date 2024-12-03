/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:31:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 18:04:03 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = "Empty Idea";
    }
    std::cout << "Brain created 100 ideas" << std::endl;
}

Brain::Brain( const Brain& other )
{
    *this = other;
}

Brain& Brain::operator=( const Brain& other )
{
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i].assign(other._ideas[i]);
    }
    std::cout << "Brain has transfered all its wisdom" << std::endl;
    return (*this);
}

Brain::~Brain( void )
{
    std::cout << "Brain has died due to overthinking" << std::endl;
}


void    Brain::setIdea( int i, std::string idea )
{
    if (i > 99 || i < 0)
    {
        std::cout << "Brain cant access this idea" << std::endl;
    }
    else
    {
        _ideas[i] = idea;
        std::cout << "New idea has poped up!" << std::endl;
    }
}

std::string Brain::getIdea( int i )
{
    if (i > 99 || i < 0)
    {
        return ("Brain cant access this idea");
    }
    else
    {
        return (_ideas[i]);
    }
}
