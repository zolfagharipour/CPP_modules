/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:43:44 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 14:15:09 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <deque>


template <typename T>
class MutantStack : public std::stack< T, std::deque<T> >
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin( void );
	iterator end( void );
	
	const_iterator begin( void ) const;
	const_iterator end( void ) const;
	
	reverse_iterator rbegin( void );
	reverse_iterator rend( void );
	
	const_reverse_iterator rbegin( void ) const;
	const_reverse_iterator rend( void ) const;
};

# include "MutantStack.tpp"

#endif