/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:38:32 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 12:26:04 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been born!" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& other )
{
    setName(other.getName());
    setHitPoint(other.getHitPoint());
    setEnergyPoint(other.getEnergyPoint());
    setAttackDamage(other.getAttackDamage());
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
    if (this == &other)
        return (*this);
    setName(other.getName());
    setHitPoint(other.getHitPoint());
    setEnergyPoint(other.getEnergyPoint());
    setAttackDamage(getAttackDamage());
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}




bool    ClapTrap::_mana( void )
{
    if (_energyPoint)
        return (1);
    std::cout << "No Mana(energy point)!" << std::endl;
    return (0);
}

bool    ClapTrap::_hp( void )
{
    if (_hitPoint)
        return (1);
    std::cout << "No HP!" << std::endl;
    return (0);
}

void    ClapTrap::_useMana( void )
{
    _energyPoint--;
}



void    ClapTrap::setName( std::string name )
{
    this->_name = name;
}

void    ClapTrap::setHitPoint( int hp )
{
    this->_hitPoint = hp;
}

void            ClapTrap::setEnergyPoint( int mana )
{
    this->_energyPoint = mana;
}

void            ClapTrap::setAttackDamage( int dmg )
{
    this->_attackDamage = dmg;
}

std::string     ClapTrap::getName( void ) const
{
    return (this->_name);
}

int      ClapTrap::getHitPoint( void ) const
{
    return(this->_hitPoint);
}

int      ClapTrap::getEnergyPoint( void ) const
{
    return(this->_energyPoint);
}

int      ClapTrap::getAttackDamage( void ) const
{
    return(this->_attackDamage);
}





void    ClapTrap::attack(const std::string& target)
{
    if (!_hp() || !_mana())
        return ;
    
    std::cout << "ClapTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage
        << " points of damage!" << std::endl;
    
    _useMana();
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    int     damage;
    
    if (_hitPoint >= (int)amount)
        damage = amount;
    else
        damage = _hitPoint;
    _hitPoint -= damage;
    
    std::cout << "ClapTrap " << _name << " recieved " << damage
        << " points of damage!\tHP: " << _hitPoint << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!_hp() || !_mana())
        return ;
    _hitPoint += amount;
    
    std::cout << "ClapTrap " << _name << " heals +" << amount
        << "\tHP: " << _hitPoint << std::endl;
    _useMana();
}
