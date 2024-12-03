/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:30:43 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 14:39:04 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	std::string		_name;
	
public:
	Cure( void );
	Cure( const Cure& other );
	Cure& operator=( const Cure& other );
	~Cure( void );

	std::string	getName( void ) const;
	AMateria*	clone( void ) const;
	void use( ICharacter& target );
};



#endif