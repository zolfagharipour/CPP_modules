/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:15:10 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/14 20:29:39 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
private:
    static const int    _fb = 8;
    int                 _nbr;
public:
    Fixed();
    Fixed( const Fixed& other );
    ~Fixed();
    Fixed&  operator=( const Fixed& other );
    
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};



#endif