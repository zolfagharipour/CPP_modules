/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:16:21 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/15 16:04:31 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void ) 
// {
//     // Fixed a;
//     // Fixed b( a );
//     Fixed d(42.42f);
//     std::cout << d.toInt() << std::endl;
//     // Fixed c;
//     // c = b;
//     // std::cout << a.getRawBits() << std::endl;
//     // std::cout << b.getRawBits() << std::endl;
//     // std::cout << c.getRawBits() << std::endl;
//     std::cout << d.getRawBits() << std::endl;
//     return 0;
// }

int
main( void ) 
{
    Fixed   a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}