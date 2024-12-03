/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:25:14 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 12:06:58 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

template <typename X>
void	Increment( X& i )
{
	i++;
}


template <typename T>
void	iter( T* array, unsigned int size, void (*f)(T&) )
{
	for (std::size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}


template <typename T>
void	iter( const T* array, unsigned int size, void (*f)(const T&) )
{
	for (std::size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

#endif