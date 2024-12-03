/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:50:53 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/01 16:52:18 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar( std::string str )
{
	t_data	data;
	
	if (str.length() == 1 && str[0] > 31 && str[0] < 127)
	{
		data.c = str[0];
		data.i = static_cast<int>(data.c);
		data.f = static_cast<float>(data.c);
		data.d = static_cast<double>(data.c);
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "char: '" << data.c << "'" << std::endl;
		std::cout << "int: " << data.i << std::endl;
		std::cout << "float: " << data.f << "f" << std::endl;
		std::cout << "double: " << data.d << std::endl;
		return (true);
	}
	return (false);
}

bool	isInt( std::string str )
{
	t_data	data;
	std::stringstream	ss(str);
	if (!isAllDigit(str))
	{
		ss >> data.i;
		if ((data.i == 2147483647 && str != "2147483647" && str != "+2147483647")
			|| (data.i == -2147483648 && str != "-2147483648"))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return (true);
		}
		data.f = static_cast<float>(data.i);
		data.d = static_cast<double>(data.i);
		
		std::cout << std::fixed << std::setprecision(1);
		if ((data.i >= 0 && data.i < 32) || data.i == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (data.i >= 32 && data.i < 127)
		{
			data.c = static_cast<char>(data.i);
			std::cout << "char: '" << data.c << "'" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << data.i << std::endl;
		std::cout << "float: " << data.f << "f" << std::endl;
		std::cout << "double: " << data.d << std::endl;
		return (true);
	}
	return (false);
}

bool	isFloat( std::string str )
{
	t_data	data;
	std::stringstream	ss(str);
	
	if (isAllDigit(str) == 2 && str[str.length() - 1] == 'f' && isJustADot(str, 2))
	{
		ss >> data.f;
		data.i = static_cast<int>(data.f);
		data.d = static_cast<double>(data.f);

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << data.i << std::endl;
		std::cout << "float: " << data.f << "f" << std::endl;
		std::cout << "double: " << data.d << std::endl;
	}
	return (false);	
}

bool	isDouble( std::string str )
{
	t_data	data;
	std::stringstream	ss(str);
	
	if (isAllDigit(str) == 1 && isJustADot(str, 1))
	{
		ss >> data.d;
		data.i = static_cast<int>(data.d);
		data.f = static_cast<float>(data.d);

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << data.i << std::endl;
		std::cout << "float: " << data.f << "f" << std::endl;
		std::cout << "double: " << data.d << std::endl;
	}
	return (false);	
}


void	ScalarConverter::convert( std::string str )
{
	if (str.empty())
	{
		std::cout << "Conversion impossible" << std::endl;
		return ;
	}
	if (isChar(str))
		return ;
	if (isInt(str))
		return ;
	if (isFloat(str))
		return ;
	if (isDouble(str))
		return ;
	if (str == "nan" || str == "nanf")
		runNan();
	else if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		runInf(str);
	else
		std::cout << "Conversion impossible" << std::endl;
}