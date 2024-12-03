/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:58:14 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 16:11:46 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    private:
        static int _scavMana;
        
    public:
        ScavTrap( std::string name );
        ~ScavTrap( void );

        void    attack( const std::string& target );
        void    guardGate( void );
        int     getScavMana( void );
};


#endif
