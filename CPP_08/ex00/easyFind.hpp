/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:10:16 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 14:42:35 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>


class NotFoundException : public std::exception{
	public:
		const char* what() const throw();
};


template <typename T>
typename T::const_iterator	easyFind( T& intContainer, const T& n );

# include "easyFind.tpp"


#endif