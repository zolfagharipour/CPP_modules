/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:41:17 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 14:39:33 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	std::string		_name;
	
public:
	Ice( void );
	Ice( const Ice& other );
	Ice& operator=( const Ice& other );
	~Ice( void );

	std::string	getName( void ) const;
	AMateria*	clone( void ) const;
	void use( ICharacter& target );
};



#endif