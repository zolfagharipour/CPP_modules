/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:10:56 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 11:25:20 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bsp.h"

Fixed   wCalOne( Point const a, Point const b, Point const c, Point const point )
{
    Fixed   w1;
    Fixed   wDenom;

    wDenom = (b.fixedY() - a.fixedY()) * (c.fixedX() - a.fixedX());
    wDenom = wDenom - (b.fixedX() - a.fixedX()) * (c.fixedY() - a.fixedY());
    std::cout << "w1 denom: " << wDenom << std::endl;
    if (wDenom == 0)
        return (0);
    w1 = a.fixedX() * (c.fixedX() - a.fixedY());
    w1 = w1 + (point.fixedY() - a.fixedY()) * (c.fixedX() - a.fixedX());
    w1 = w1 - point.fixedX() * (c.fixedY() - a.fixedY());
    std::cout << "w1nom: " << w1 << std::endl;
    std::cout << "w1: " << w1 / wDenom << std::endl;
    return (w1 / wDenom);
    
}

Fixed   wCalTwo( Point const a, Point const b, Point const c, Point const point, Fixed w1 )
{
    Fixed   w2;

    std::cout << "w2 denom: " << c.fixedY() - a.fixedY() << std::endl;
    if (c.fixedY() == a.fixedY())
        return (0);
    w2 = point.fixedY() - a.fixedY() - w1 * (b.fixedY() - a.fixedY());
    std::cout << "w2 nom: " << w2 << std::endl;
    w2 = w2 / (c.fixedY() - a.fixedY());
    std::cout << "w2: " << w2 << std::endl;
    return (w2);
}

bool    bsp( Point const a, Point const b, Point const c, Point const point ) 
{
    Fixed w1;
    Fixed w2;

    w1 = wCalOne(a, b, c, point);
    w2 = wCalTwo(a, b, c, point, w1);

    if (w2 == 0 || w1 == 0)
    {        
        w1 = wCalOne(b, c, a, point);
        w2 = wCalTwo(b, c, a, point, w1);
    }
    if (w1 <= 0 || w2 <= 0 || w1 + w2 >= 1)
        return (false);
    return (true);
}