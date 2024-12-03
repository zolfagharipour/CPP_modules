/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:32:50 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/14 11:45:51 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "The Convertor needs one and only one argument." << std::endl;
		return (1);
	}
	std::string		str = av[1];
	ScalarConverter::convert(str);
}