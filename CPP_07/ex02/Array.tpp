/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:50:58 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 12:45:55 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
Array<T>::Array( void ) : _array(new T[0]()), _size(0)
{
}

template <typename T>
Array<T>::Array( unsigned int n ) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array( const Array& other ) : _array(new T[other.size()]()), _size(other.size())
{
	for (std::size_t i = 0; i < _size; i++)
	{
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& other )
{
	if (this == &other)
		return (*this);
	delete[] _array;
	_array = new T[other.size()]();
	for (std::size_t i = 0; i < _size; i++)
	{
		this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] _array;
}


template <typename T>
T&	Array<T>::operator[]( std::size_t n )
{
	if (n >= _size)
		throw OutOfBoundException();
	return (_array[n]);
}

template <typename T>
std::size_t	Array<T>::size( void ) const
{
	return (_size);
}

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of array bound");
}