/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:31:28 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 16:14:34 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main( int ac, char* av[])
{
	if (ac < 2)
	{
		std::cerr << "I need a File as input argument" << std::endl;
		return (0);
	}
	
	try{
		BitcoinExchange	bce("data.csv");
		bce.inputFile(av[1]);
		bce.print();
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
