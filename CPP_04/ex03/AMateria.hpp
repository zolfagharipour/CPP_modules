/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:03:18 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/13 14:45:06 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string		_type;
	
public:
	AMateria( std::string const & type );
	AMateria( const AMateria& other );
	AMateria& operator=( const AMateria& other );
	virtual ~AMateria( void );

	
	std::string const& getType( void ) const;
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );
};



#endif