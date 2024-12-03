/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:44:10 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/01 16:53:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


int	isAllDigit( std::string str )
{
	int i = 0;
	int noDigit = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			noDigit++;
		i++;
	}
	return (noDigit);
}
bool	isJustADot( std::string str, int mode)
{
	std::size_t	i = 0;
	int			dot = 0;

	if(str[str.length() - mode] == '.')
		return (false);
	while (i < str.length())
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot == 1)
		return (true);
	return (false);
}

void	runNan( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	runInf( std::string str )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[0] == '+')
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
