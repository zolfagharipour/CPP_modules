/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:54:47 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 11:56:12 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


void	decrementInt( int& i )
{
	i--;
}

void	decrementChar( char& i )
{
	i--;
}

int	main()
{
	char	s[6] = "12345";
	
	std::cout << "Char:\t" << s << " ---> ";
	iter(s, 5, &Increment);
	std::cout << s << " ---> ";
	iter(s, 5, &decrementChar);
	std::cout << s << std::endl;


	int		i[7] = {0, 0, 1, 2, 4, 7, 12};
		
	std::cout << "Int:\t";
	for (int x = 0; x < 7; x++)
	{
		std::cout << i[x] << ",";
	}
	std::cout << " ---> ";
	iter(i, 7, &Increment);
	for (int x = 0; x < 7; x++)
	{
		std::cout << i[x] << ",";
	}
	iter(i, 7, &decrementInt);
	std::cout << " ---> ";
		for (int x = 0; x < 7; x++)
	{
		std::cout << i[x] << ",";
	}
	std::cout << std::endl;

}