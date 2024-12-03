/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:38:57 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/23 14:25:21 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie* zom;
	
	try{
		zom = new Zombie;
	}
	catch (std::bad_alloc& e){
		return (NULL);
	}
	zom->setName(name);
	return (zom);
}
