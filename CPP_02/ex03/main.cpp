/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:16:21 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 11:25:04 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bsp.h"

int main( void ) {
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 0);
    
    Point p(2, 2);
    
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;
    std::cout << bsp(a, b, c, p) << std::endl;
}