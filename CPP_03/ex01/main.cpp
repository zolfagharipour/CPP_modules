/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:39:06 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/26 16:33:52 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap    scav("Scav");
    ScavTrap    scav1(scav);
    ScavTrap    scav2 = scav1;

    scav1.attack("Scav2");
    scav2.takeDamage(scav1.getAttackDamage());
    scav2.beRepaired(12);
    scav.guardGate();
    
}