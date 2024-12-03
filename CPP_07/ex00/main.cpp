/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:54:47 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/02 13:22:56 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int	main()
{
	char	c1 = 'm', c2 = 'M';
	int		i1 = -1, i2 = 4;
	float	f1 = 2.3, f2 = 43.2;
	std::string	s1 = "Hello", s2 = "World";


	std::cout << "-----SWAP-----" << std::endl;
	
	std::cout << c1 << "/" << c2 << " ---> ";
	::swap(c1, c2);
	std::cout << c1 << "/" << c2 << std::endl;

	std::cout << i1 << "/" << i2 << " ---> ";
	::swap(i1, i2);
	std::cout << i1 << "/" << i2 << std::endl;

	std::cout << f1 << "/" << f2 << " ---> ";
	::swap(f1, f2);
	std::cout << f1 << "/" << f2 << std::endl;

	std::cout << s1 << "/" << s2 << " ---> ";
	::swap(s1, s2);
	std::cout << s1 << "/" << s2 << std::endl;




	std::cout << "\n\n-----MIN-----" << std::endl;
	
	std::cout << c1 << "/" << c2 << " ---> " << ::min(c1, c2) << std::endl;
	std::cout << i1 << "/" << i2 << " ---> " << ::min(i1, i2) << std::endl;
	std::cout << f1 << "/" << f2 << " ---> " << ::min(f1, f2) << std::endl;
	std::cout << s1 << "/" << s2 << " ---> " << ::min(s1, s2) << std::endl;



	
	std::cout << "\n\n-----MAX-----" << std::endl;

	std::cout << c1 << "/" << c2 << " ---> " << ::max(c1, c2) << std::endl;
	std::cout << i1 << "/" << i2 << " ---> " << ::max(i1, i2) << std::endl;
	std::cout << f1 << "/" << f2 << " ---> " << ::max(f1, f2) << std::endl;
	std::cout << s1 << "/" << s2 << " ---> " << ::max(s1, s2) << std::endl;

}