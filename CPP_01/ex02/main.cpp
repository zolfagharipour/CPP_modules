/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:17:11 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/27 15:48:13 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout << "Addresses:" << std::endl;
	std::cout << "str:\t" << &str << std::endl;
	std::cout << "ptr:\t" << stringPTR << std::endl;
	std::cout << "ref:\t" << &stringREF << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << "str:\t" << str << std::endl;
	std::cout << "ptr:\t" << *stringPTR << std::endl;
	std::cout << "ref:\t" << stringREF << std::endl;

	// str.append("!");
	
	// std::cout << "Values after edit:" << std::endl;
	// std::cout << "str:\t" << str << std::endl;
	// std::cout << "ptr:\t" << *stringPTR << std::endl;
	// std::cout << "ref:\t" << stringREF << std::endl;

}
