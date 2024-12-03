/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:41:00 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/08 14:09:59 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zomb;

	zomb = newZombie("foo");
	if (!zomb)
		return (0);
	zomb->announce();
	randomChump("randooo");
	delete zomb;
}