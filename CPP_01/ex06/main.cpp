/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:10:07 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/13 17:26:17 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		karen;
	std::string	str;
	
	if (ac == 1)
	{
		std::cout << "I need an argument!" << std::endl;
		return (0);
	}
	str = av[1];
	karen.complain(str);
}
