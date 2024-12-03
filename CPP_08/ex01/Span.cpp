/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:41:18 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 20:58:56 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span( void ) : _n(0), _array(0), _it(0)
{
}

Span::Span( unsigned int n ) : _n(n), _array(new int[n]()), _it(0)
{
}
Span::Span( const Span& other )
{
	_it = 0;
	_n = other.size();
	_array = new int[_n];
	for (unsigned int i = 0; i < other.size(); i++)
		_array[i] = other._array[i];
}

Span& Span::operator=( const Span& other )
{
	if (this == &other)
		return (*this);

	_it = other.where();
	delete[] _array;
	_array = new int[_n];
	for (unsigned int i = 0; i < other.size(); i++)
		_array[i] = other._array[i];
	return (*this);
}

Span::~Span( void ) 
{
	delete[] _array;
}

int& Span::operator[]( std::size_t i )
{
	return (_array[i]);
}

void	Span::addNumber( int nbr )
{
	if (_it >= _n)
		throw MaxLimitReached();
	_array[_it] = nbr;
	_it++;
}
void	Span::addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	unsigned int newSize = std::distance (begin, end);

	if (newSize > _n - _it)
		throw RangeDoesNotFit();
	std::copy(begin, end, _array + _it);
	_it += newSize;
}

int	Span::shortestSpan( void )
{
	int	sortedArray[_it];
	int	shortest = INT_MAX;

	if (_it < 2)
		throw NotEnoughElements();
	std::copy(_array, _array + _it, sortedArray);
	std::sort(sortedArray, sortedArray + _it);
	for (unsigned int i = 0; i < _it - 1; i ++)
	{
		if (abs(sortedArray[i] - sortedArray[i + 1]) < shortest)
			shortest = abs(sortedArray[i] - sortedArray[i + 1]);
	}
	return (shortest);
}

int	Span::longestSpan( void )
{
	if (_it < 2)
		throw NotEnoughElements();
	return (abs(*std::max_element(_array, _array + _it) - *std::min_element(_array, _array + _it)));
}


unsigned int	Span::size( void ) const
{
	return (_n);
}

unsigned int	Span::where( void ) const
{
	return (_it);
}

const char*	Span::MaxLimitReached::what() const throw()
{
	return ("Maximum capacity reached");
}

const char* Span::RangeDoesNotFit::what() const throw()
{
	return ("New range is more than capacity");
}

const char * Span::NotEnoughElements::what() const throw()
{
	return ("Not enough elements");
}
