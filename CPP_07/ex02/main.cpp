/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:54:47 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/15 12:46:16 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"





int	main()
{
	std::cout << "---CONSTRUCTION---\n (if all good nothing should be shown here)" << std::endl;
	Array<int>	i(10);
	Array<int>	i0;
	Array<char> c(11);
	Array<float> f(3);
	Array<std::string> s(3);
	
	std::cout << "\n\n---EXCEPTION---" << std::endl;
	try{
		std::cout << i[10] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << i0[0] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << f[-1] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n---WRITING & READING & SIZE---" << std::endl;
	i[0] = 1;
	c[0] = 'H';
	f[0] = 3.14;
	s[0] = "Hello World";
	std::cout << "i: " << i[0] << "\t with size of " << i.size() << std::endl;
	std::cout << "c: " << c[0] << "\t with size of " << c.size() << std::endl;
	std::cout << "f: " << f[0] << "\t with size of " << f.size() << std::endl;
	std::cout << "s: " << s[0] << "\t with size of " << s.size() << std::endl;
	std::cout << "size of i0: " << i0.size() << std::endl;
	
	std::cout << "\n\n---COPY ASSIGNEMENT AND COPY CONSTRUCTION---" << std::endl;
	Array<int>	i1(i);
	Array<int>	i2 = i;
	std::cout << "i1: " << i1[0] << std::endl;
	std::cout << "i2: " << i2[0] << std::endl;

}