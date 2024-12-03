/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:00:11 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/08 14:11:16 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	zombs;
	int		N = 4;
	
	zombs = zombieHorde(N, "mohamad");
	if (!zombs)
		return (0);
	for (int i = 0; i < N; i++)
	{
		zombs[i].announce();
	}
	delete[] zombs;
}