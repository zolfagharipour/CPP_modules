/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:14:53 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/23 15:22:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sifl.hpp"

int	openFiles(Sifl& sifl)
{
	sifl.myFile.open(sifl.fileName.c_str(), std::ios::in);
	if (!sifl.myFile.is_open())
	{
		std::cout << sifl.fileName << " can not be open." << std::endl;
		return (0);
	}
	else if (sifl.s1 == "")
	{
		std::cout << "S1 can not be empty." << std::endl;
		return (0);
	}
	sifl.newFile.open((sifl.fileName + ".replace").c_str(), std::ios::out);
	if (!sifl.newFile.is_open())
	{
		std::cout << sifl.fileName << ".replace can not be empty." << std::endl;
		sifl.myFile.close();
		return (0);
	}
	return (1);
}

void	readNreplace(Sifl& sifl)
{
	size_t	pos = 0;
	
	while (getline(sifl.myFile, sifl.read))
	{
		pos = 0;
		pos = sifl.read.find(sifl.s1, pos);
		while (pos < sifl.read.length())
		{
			sifl.read.erase(pos, sifl.s1.length());
			sifl.read.insert(pos, sifl.s2);
			pos = sifl.read.find(sifl.s1, pos);
		}
		sifl.newFile << sifl.read << std::endl;
	}
}

int	main(int ac, char** av)
{
	Sifl	sifl;

	if (ac < 4)
	{
		std::cout << "I need 3 arguments!" << std::endl;
		return (0);
	}
	sifl.fileName = av[1];
	sifl.s1 = av[2];
	sifl.s2 = av[3];	
	if (!openFiles(sifl))
		return (0);
	readNreplace(sifl);
	sifl.myFile.close();
	sifl.newFile.close();
}