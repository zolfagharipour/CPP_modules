/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeDe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:44:19 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 14:47:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEDE_HPP
# define PMERGEDE_HPP

# include <deque>

# include <string>
# include <iostream>
# include <algorithm>
# include <cmath>

class PmergeDe
{
private:
	std::deque<int>					_data;
	std::deque<unsigned int>		_jakobsThal;
	int								_comparisons;
	int								_depth;

	std::deque< std::deque<int> >*		_sort( void );
	std::deque< std::deque<int> >*		_divide( std::deque< std::deque<int> >& motherSet );
	std::deque< std::deque<int> >*		_conquer( std::deque< std::deque<int> >& motherSet );
	std::deque< std::deque<int> >*		_bottomRecursion( std::deque< std::deque<int> >& motherSet );
	int									_binaryInsert( std::deque<int>& sorteddeque,int upperBound, int nbr );
	void								_printMother( std::deque< std::deque<int> > motherSet );
	void								_createJakob( unsigned int size );
	void								_isItSorted(const std::deque<int>& vec);


public:
	PmergeDe( void );
	PmergeDe( const std::deque<int>& input );
	PmergeDe( const PmergeDe& other );
	~PmergeDe( void );
	
	PmergeDe& operator=( const PmergeDe& other );

	const std::deque<int>	getData( void ) const;

	void	print( void );
};

#endif