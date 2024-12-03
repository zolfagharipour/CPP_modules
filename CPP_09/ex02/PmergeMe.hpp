/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:44:19 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 14:44:30 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>

# include <string>
# include <iostream>
# include <algorithm>
# include <cmath>

class PmergeMe
{
private:
	std::vector<int>				_data;
	std::vector<unsigned int>		_jakobsThal;
	int								_comparisons;
	int								_depth;

	std::vector< std::vector<int> >*	_sort( void );
	std::vector< std::vector<int> >*	_divide( std::vector< std::vector<int> >& motherSet );
	std::vector< std::vector<int> >*	_conquer( std::vector< std::vector<int> >& motherSet );
	std::vector< std::vector<int> >*	_bottomRecursion( std::vector< std::vector<int> >& motherSet );
	int									_binaryInsert( std::vector<int>& sortedVector,int upperBound, int nbr );
	void								_printMother( std::vector< std::vector<int> > motherSet );
	void								_isItSorted(const std::vector<int>& vec);
	void								_createJakob( unsigned int size );


public:
	PmergeMe( void );
	PmergeMe( const std::vector<int>& input );
	PmergeMe( const PmergeMe& other );
	~PmergeMe( void );
	
	PmergeMe& operator=( const PmergeMe& other );

	const std::vector<int>	getData( void ) const;

	void	print( void );
};

#endif