/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 13:21:36 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int	main()
{
	{
		std::cout << "---42 MAIN---" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n\n---TESTING ADDNUMBER & EXCEPTION---" << std::endl;
		Span	span(3);
		
		span.addNumber(-5);
		span.addNumber(2);
		span.addNumber(3);

		for (int i = 0; i < 3; i++)
		{
			std::cout << span[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
			<< span.shortestSpan() << std::endl;
		try{
			span.addNumber(12);
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n---TESTING ADDNUMBERS FOR RANGE & EXCEPTION---" << std::endl;
		int					arr[] = {1, 2, 3, -4, 5};
		std::vector<int>	v(arr, arr + 5);
		Span	span(8);
		span.addNumbers(v.begin(), v.end());
		for (int i = 0; i < 5; i++)
		{
			std::cout << span[i] << " ";
		}
		std::cout << std::endl;
		try{
			span.addNumbers(v.begin(), v.end());
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
			<< span.shortestSpan() << std::endl;
	}
	{
		std::cout << "\n\n---EXCEPTION FOR NO OR ONE ELEMENT---" << std::endl;
		Span	span(10);
		try{
			std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
				<< span.shortestSpan() << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		span.addNumber(10);
		try{
			std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
				<< span.shortestSpan() << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		span.addNumber(10);
		try{
			std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
				<< span.shortestSpan() << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}	
	}
	{
		std::cout << "\n\n---HUGE SPAN---" << std::endl;
		Span	span(100000);
		int		random;

		std::srand(static_cast<unsigned>(std::time(0)));
		for (unsigned int i = 0; i < 100000; i++)
		{
			random = std::rand();
			span.addNumber(random);
		}
		std::cout << "longest span: " << span.longestSpan() << "\t shortest span: "
				<< span.shortestSpan() << std::endl;
	}
}