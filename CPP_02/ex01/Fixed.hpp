/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:15:10 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 11:02:25 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
private:
    static const int    _fb = 8;
    int                 _nbr;
public:
    Fixed();
    Fixed( const int nbr );
    Fixed( const float nbr );
    Fixed( const Fixed& other );
    ~Fixed();
    Fixed&  operator=( const Fixed& other );
    
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream&  operator<<( std::ostream& os, const Fixed& other);


#endif