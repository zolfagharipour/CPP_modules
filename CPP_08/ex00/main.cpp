/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:46:04 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 15:26:46 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <list>
#include <vector>
#include <deque>

int	main()
{
	{
		std::cout << "---LIST---" << std::endl;
		std::list<int>	intList;
		intList.push_back(1);
		intList.push_back(2);
		intList.push_back(4);
		intList.push_back(8);
		intList.push_back(16);

		std::cout << *easyFind(intList, 4) << std::endl;
		std::cout << *easyFind(intList, 16) << std::endl;
		std::cout << *easyFind(intList, 1) << std::endl;

		try{
			std::cout << *easyFind(intList, 3) << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "---CONST DEQUE---" << std::endl;
		std::deque<int>	tmpDeque;
		tmpDeque.push_back(-1);
		tmpDeque.push_back(-12);
		tmpDeque.push_back(1);
		tmpDeque.push_back(4);
		tmpDeque.push_back(3);
		tmpDeque.push_back(-9);
		const std::deque<int>	intDeque = tmpDeque;

		std::cout << *easyFind(intDeque, -1) << std::endl;
		std::cout << *easyFind(intDeque, 1) << std::endl;
		std::cout << *easyFind(intDeque, -12) << std::endl;
		try{
			std::cout << *easyFind(intDeque, 0) << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "---\n\nFINDING INDEX IN CONST VECTOR---" << std::endl;
		const int				tmp[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
		const std::vector<int>	intVector(tmp, tmp + 10);
		std::vector<int>::const_iterator it = easyFind(intVector, 14);

		std::size_t i = intVector.size();
		while (it != intVector.end())
		{
			i--;
			it++;
		}
		std::cout << "The index of 14 in array is " << i << std::endl;
	}
}
