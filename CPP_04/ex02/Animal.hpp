/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:19 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/15 12:40:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
    std::string     _type;
    
public:
    Animal( void );
    Animal ( const Animal& other );
    Animal& operator=( const Animal& other );
    virtual ~Animal();

    std::string     getType( void ) const;
    virtual void    makeSound( void ) const = 0;
};


#endif
