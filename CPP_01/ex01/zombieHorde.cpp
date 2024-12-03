/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:51:17 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/08 14:10:42 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombs;

	try{
		zombs = new Zombie[N];
	}
	catch(std::bad_alloc& e){
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		zombs[i].setName(name);
	}
	return (zombs);
}