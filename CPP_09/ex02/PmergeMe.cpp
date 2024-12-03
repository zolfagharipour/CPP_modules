/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:46:14 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 15:36:56 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe( void ) : _comparisons(0), _depth(0)
{
}

PmergeMe::PmergeMe( const std::vector<int>& input ) : _data(input), _comparisons(0), _depth(0)
{
}

PmergeMe::PmergeMe( const PmergeMe& other )
{
	*this = other;
}


PmergeMe::~PmergeMe( void )
{
}


PmergeMe& PmergeMe::operator=( const PmergeMe& other )
{
	if (this == &other)
		return (*this);
	_data = other.getData();
	return (*this);
}

const std::vector<int>	PmergeMe::getData( void ) const
{
	return (_data);
}


void	PmergeMe::print( void )
{
	std::vector< std::vector<int> >*	sortedVector;
	sortedVector = _sort();
	_printMother(*sortedVector);
	// std::cout << "number of comparisons:\t" << _comparisons << std::endl;
	delete sortedVector;
}

