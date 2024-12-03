/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:46 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 12:33:17 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name )
    : ClapTrap (name + "_clap_name")
    , ScavTrap (name + "_clap_name")
    , FragTrap(name + "_clap_name")
    , _name(name)
{
    std::cout << "DiamondTrap " << _name << " has been born!" << std::endl;  
    setEnergyPoint(getScavMana());
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " is dead!" << std::endl;  
}

void    DiamondTrap::attack( const std::string& target )
{
    ScavTrap::attack(target);
}

void    DiamondTrap::WhoAmI( void )
{
    std::cout << "My ClapTrap name is "
        << this->getName()
        << "\nBut people know me by my DiamondTrap name: "
        << _name << std::endl;
}
