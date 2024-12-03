/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:15:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 11:02:19 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_nbr = 0;
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(other);
}

Fixed::Fixed( const int nbr )
{
    setRawBits(nbr<<this->_fb);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float nbr )
{
    setRawBits(roundf(nbr * (1<< this->_fb)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    setRawBits(other.getRawBits());
    return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return (os);
}

int Fixed::getRawBits( void ) const
{
    return(this->_nbr);
}

void    Fixed::setRawBits( int const raw )
{
    this->_nbr = raw;
}
float   Fixed::toFloat( void ) const
{
    return ((getRawBits() / float(256)));
}

int     Fixed::toInt( void ) const
{
    return (getRawBits() >> 8);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
