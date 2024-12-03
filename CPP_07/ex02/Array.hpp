/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:31:45 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/02 17:07:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
private:
	T*			_array;
	std::size_t _size;

	void	_copy( T& other );
public:
	Array( void );
	Array( unsigned int n );
	Array( const Array& other );
	Array& operator=( const Array& other );
	~Array( void );

	T&	operator[]( std::size_t n );
	std::size_t	size( void ) const;

	class OutOfBoundException : public std::exception {
	public:
		const char* what() const throw();
	};
};

# include "Array.tpp"


#endif