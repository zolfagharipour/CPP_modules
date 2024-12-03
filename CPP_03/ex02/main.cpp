/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:06 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/26 16:55:57 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap    Frag("Frag");
    FragTrap    Frag1(Frag);
    FragTrap    Frag2 = Frag1;

    Frag1.attack("Frag2");
    Frag2.takeDamage(Frag1.getAttackDamage());
    Frag2.beRepaired(12);
    Frag.highFivesGuys();
    
}