/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:09:50 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/07 15:21:42 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain*  _brain;
    
public:
    Dog( void );
    Dog( const Dog& other );
    Dog& operator=( const Dog& other );
    ~Dog( void );

    void        makeSound( void ) const;
    void        steIdea( int i, std::string idea );
    std::string getIdea ( int i );

};


#endif
