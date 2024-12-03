/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:45 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/31 14:11:46 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>
# include "utils.h"

class Serializer
{
private:
	Serializer( void );
	Serializer( const Serializer& other );
	Serializer& operator=( const Serializer& other );
	~Serializer( void );
public:
	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );
};




#endif