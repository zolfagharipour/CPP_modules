/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:54:40 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/02 13:17:54 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <string>
# include <iostream>

template <typename T>

void	swap( T& first, T& second )
{
	T	tmp;

	tmp = second;
	second = first;
	first = tmp;
}


template <typename T>
T	min( T first, T second )
{
	return (first < second ? first : second);
}


template <typename T>
T	max( T first, T second )
{
	return (first > second ? first : second);
}

#endif