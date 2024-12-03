/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:13:28 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 14:23:42 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin( void )
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
	return (this->c.end());
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::begin( void ) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const
{
	return (this->c.end());
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rbegin( void )
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend( void )
{
	return (this->c.rend());
}

template <typename T>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::rbegin( void ) const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend( void ) const
{
	return (this->c.rend());
}