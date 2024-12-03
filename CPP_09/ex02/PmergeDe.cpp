/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeDe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:48:42 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 15:48:49 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeDe.hpp"


PmergeDe::PmergeDe( void ) : _comparisons(0), _depth(0)
{
}

PmergeDe::PmergeDe( const std::deque<int>& input ) : _data(input), _comparisons(0), _depth(0)
{
}

PmergeDe::PmergeDe( const PmergeDe& other )
{
	*this = other;
}


PmergeDe::~PmergeDe( void )
{
}


PmergeDe& PmergeDe::operator=( const PmergeDe& other )
{
	if (this == &other)
		return (*this);
	_data = other.getData();
	return (*this);
}

const std::deque<int>	PmergeDe::getData( void ) const
{
	return (_data);
}

void	PmergeDe::print( void )
{
	std::deque< std::deque<int> >*	sortedDeque;
	sortedDeque = _sort();
	// _printMother(*sortedDeque);
	// std::cout << "number of comparisons:\t" << _comparisons << std::endl;
	delete sortedDeque;
}
