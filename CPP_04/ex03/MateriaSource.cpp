/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:41:20 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/15 12:19:41 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	*this = other;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (other._materia[i])
		{
			if (_materia[i])
				delete (_materia[i]);
			_materia[i] = other._materia[i];
		}
		else
			_materia[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if(_materia[i])
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (&_materia[j] == &_materia[i])
					_materia[j] = NULL;
			}
			delete (_materia[i]);
		}
	}
}

void	MateriaSource::learnMateria( AMateria* materia )
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = materia;
			return ;
		}
	}	
}
AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && type ==_materia[i]->getType())
			return (_materia[i]->clone());
	}
	return (NULL);
}
