/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:38:29 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/14 13:27:36 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character( std::string name )
{
	std::cout << "Character " << name << " has been created." << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character( const Character& other )
{
	std::cout << "Character " << other._name << " has been created." << std::endl;
	for (int i = 0; i < 4; i++)
		_slot[i] = NULL;
	*this = other;
}

Character& Character::operator=( const Character& other )
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i])
		{
			delete (_slot[i]);
			_slot[i] = NULL;
		}
		if (other._slot[i])
			_slot[i] = other._slot[i];
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character " << _name << " has been destroyed." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i])
			delete (_slot[i]);
	}
}


std::string const& Character::getName( void ) const
{
	return (_name);
}

void Character::equip( AMateria* m )
{
	for (int i = 0; i < 4; i++)
	{
		if (!_slot[i])
		{
			_slot[i] = m;
			return ;
		}
	}
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
		_slot[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && _slot[idx])
		_slot[idx]->use(target);
}