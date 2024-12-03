/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:00:15 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 12:30:17 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << name << " has been born!" << std::endl;  
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
}

void    FragTrap::attack( const std::string& target )
{
    if (!_hp() || !_mana())
        return ;
    
    std::cout << "FragTrap " << getName() << " attacks " << target
        << ", causing " << getAttackDamage()
        << " points of damage!" << std::endl;
    
    this->_useMana();
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "Positive high fives!" << std::endl;
}
