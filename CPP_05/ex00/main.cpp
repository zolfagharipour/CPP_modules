/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/14 11:02:36 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{	
	std::cout << "---MAX---" << std::endl;
	try{
		Bureaucrat max;
		std::cout << max << std::endl;
		max.incrementGrade();
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\n---SAM---" << std::endl;
	try{
		Bureaucrat sam("Sam", 5);
		std::cout << sam << std::endl;
		sam.incrementGrade();
		std::cout << sam << std::endl;
		sam.decrementGrade();
		std::cout << sam << std::endl;
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n---JIM---" << std::endl;
	try{
		Bureaucrat jim("Jim", -1);
		std::cout << jim << std::endl;
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n---JON---" << std::endl;
	try{
		Bureaucrat jon("Jon", 151);
		std::cout << jon << std::endl;
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n---TOM---" << std::endl;
	try{
		Bureaucrat	tom("tom", 140);
		std::cout << tom << std::endl;
		for (int i = 0; i < 11; i++)
		{
			tom.decrementGrade();
			std::cout << tom << std::endl;
		}
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	
	std::cout << "\n\nEnd of main." << std::endl;

}