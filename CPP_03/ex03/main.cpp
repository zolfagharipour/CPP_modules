/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:06 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 11:49:59 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dia("dia");
    ScavTrap    scav("scav");
    FragTrap    frag("frag");

    std::cout << "HITPOINT:" << std::endl;
    std::cout << "DIA:  " <<  dia.getHitPoint() << std::endl;
    std::cout << "SCAV: " << scav.getHitPoint() << std::endl;
    std::cout << "FRAG: " << frag.getHitPoint() << std::endl;
    
    std::cout << "ENERGYPOINT:" << std::endl;
    std::cout << "DIA:  " <<  dia.getEnergyPoint() << std::endl;
    std::cout << "SCAV: " << scav.getEnergyPoint() << std::endl;
    std::cout << "FRAG: " << frag.getEnergyPoint() << std::endl;

    std::cout << "ATTACKDAMAGE:" << std::endl;
    std::cout << "DIA:  " <<  dia.getAttackDamage() << std::endl;
    std::cout << "SCAV: " << scav.getAttackDamage() << std::endl;
    std::cout << "FRAG: " << frag.getAttackDamage() << std::endl;

    std::cout << "HITPOINT:" << std::endl;

    std::cout << "--------------" << std::endl;
    dia.guardGate();
    std::cout << "--------------" << std::endl;
    dia.highFivesGuys();
    std::cout << "--------------" << std::endl;
    dia.attack("peter");
    std::cout << "--------------" << std::endl;
    dia.WhoAmI();
}