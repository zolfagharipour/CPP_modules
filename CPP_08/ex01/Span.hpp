/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:40:50 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 20:58:49 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>


class Span
{
private:
	unsigned int	_n;
	int*			_array;
	unsigned int	_it;
	
public:
	Span( void );
	Span( unsigned int n );
	Span( const Span& other );
	~Span( void );

	Span& operator=( const Span& other );
	int& operator[]( std::size_t i );

	void			addNumber( int nbr );
	void			addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end );
	int				shortestSpan( void );
	int				longestSpan( void );
	unsigned int	size( void ) const;
	unsigned int	where( void ) const;

	class MaxLimitReached : public std::exception {
		public:
			const char*	what() const throw();
	};
	
	class RangeDoesNotFit : public std::exception {
		public:
			const char* what() const throw();
	};

	class NotEnoughElements : public std::exception {
		public:
			const char * what() const throw();
	};
};

#endif