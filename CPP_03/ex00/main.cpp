/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:06 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/26 15:45:14 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    clap("Clap");
    ClapTrap    clap1(clap);
    ClapTrap    trap("Trap");
    ClapTrap    trap1 = trap;
    

    clap1.attack("Trap");
    trap1.takeDamage(9);
    trap1.beRepaired(5);
    trap1.attack("Clap");
    clap1.takeDamage(3000);
    clap1.beRepaired(9000);
    clap1.attack("Trap");
    
}