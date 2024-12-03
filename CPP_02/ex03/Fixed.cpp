/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:15:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/17 15:17:57 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_nbr = 0;
}

Fixed::Fixed( const Fixed& other )
{
    Fixed::operator=(other);
}

Fixed::Fixed( const int nbr )
{
    setRawBits(nbr<<this->_fb);
}

Fixed::Fixed( const float nbr )
{
    setRawBits(roundf(nbr * (1<< this->_fb)));
}

Fixed& Fixed::operator=( const Fixed& other )
{
    if (this == &other)
        return (*this);
    setRawBits(other.getRawBits());
    return (*this);
}

std::ostream& operator<<( std::ostream &os, const Fixed& other)
{
    os << other.toFloat();
    return (os);
}

bool  Fixed::operator<( const Fixed& other ) const
{
    return (this->_nbr < other._nbr);
}

bool  Fixed::operator<=( const Fixed& other ) const
{
    return (this->_nbr <= other._nbr);
}

bool  Fixed::operator>( const Fixed& other ) const
{
    return (this->_nbr > other._nbr);
}

bool  Fixed::operator>=( const Fixed& other ) const
{
    return (this->_nbr >= other._nbr);
}

bool  Fixed::operator==( const Fixed& other ) const
{
    return (this->_nbr == other._nbr);
}

bool  Fixed::operator!=( const Fixed& other ) const
{
    return (this->_nbr != other._nbr);
}


Fixed Fixed::operator+( const Fixed& other ) const
{
    Fixed a;
    a.setRawBits(this->_nbr + other._nbr);
    return (a);
}
Fixed Fixed::operator-( const Fixed& other ) const
{
    Fixed a;
    a.setRawBits(this->_nbr - other._nbr);
    return (a);
}
Fixed Fixed::operator*( const Fixed& other ) const
{
    Fixed a;
    a.setRawBits((this->_nbr * other._nbr) >> this->_fb);
    return (a);
}
Fixed Fixed::operator/( const Fixed& other ) const
{
    Fixed a;
    a.setRawBits((this->_nbr << this->_fb)/ other._nbr);
    return (a);
}

Fixed&  Fixed::operator++( void )
{
    this->_nbr++;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed tmp(*this);
    this->_nbr++;
    return (tmp);
}

Fixed&  Fixed::operator--( void )
{
    this->_nbr--;
    return (*this);
}

Fixed Fixed::operator--( int )
{
    Fixed tmp(*this);
    this->_nbr--;
    return (tmp);
}

Fixed& Fixed::min( Fixed& first, Fixed& second )
{
    if (first > second)
        return (second);
    return (first);
}

const Fixed& Fixed::min( const Fixed& first, const Fixed& second )
{
    if (first > second)
        return (second);
    return (first);
}

Fixed& Fixed::max( Fixed& first, Fixed& second )
{
    if (first < second)
        return (second);
    return (first);
}

const Fixed& Fixed::max( const Fixed& first, const Fixed& second )
{
    if (first < second)
        return (second);
    return (first);
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
}

