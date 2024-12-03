/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:55:49 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 15:38:06 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeDe.hpp"
#include <sstream>
#include <ctime>

int	main( int ac, char* av[] )
{
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::clock_t		start, end;
	std::stringstream	ss;
	int					nbr;
	double				elapseTime;

	if (ac < 2)
	{
		std::cerr << "I need at least one argument to sort" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		ss.clear();
		ss.str(av[i]);
		ss >> nbr;
		if (ss.fail())
		{
			std::cerr << "Input is not valid -> " << av[i] << std::endl;
			return (0);
		}
		vec.push_back(nbr);
		deq.push_back(nbr);
	}

	std::cout << "Before: ";
	for (int i = 0; i < ac - 1; i++)
		std::cout << vec[i] << " ";
	std::cout << "\nAfter: ";


	PmergeMe	pmergeV(vec);
	PmergeDe	pmergeD(deq);
	
	start = std::clock();
	pmergeV.print();
	end = std::clock();
	elapseTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector " << elapseTime * 1000000.0 << " us" << std::endl;
		
	start = std::clock();
	pmergeD.print();	
	end = std::clock();
	elapseTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque " << elapseTime * 1000000.0 << " us" << std::endl;
}