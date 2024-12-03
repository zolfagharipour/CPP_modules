/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:30:38 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/22 13:25:33 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string	str;
	
	std::cout << "Please chose your operation:(ADD, SEARCH, EXIT)\t";
	std::getline(std::cin, str);

	while (str != "EXIT" && str != "exit" && !std::cin.eof())
	{
		std::cout << str << std::endl;
		if (str == "ADD" || str == "add")
			pb.AddContact();
		else if(str == "SEARCH" || str == "search")
			pb.SearchContact();
		std::cout << "Please chose your operation:(ADD, SEARCH, EXIT)\t";
		std::getline(std::cin, str);
	}
	return (0);
}