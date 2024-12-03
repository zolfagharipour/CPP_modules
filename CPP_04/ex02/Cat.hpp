/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:41:17 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/07 15:23:54 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal
{
private:
    Brain*  _brain;
public:
    Cat( void );
    Cat( const Cat& other );
    Cat& operator=( const Cat& other );
    ~Cat( void );

    void        makeSound( void ) const;
    void        steIdea( int i, std::string idea );
    std::string getIdea ( int i );
};


#endif
