/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/12 10:52:19 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{	
	std::cout << "---NO EXCEPTION---" << std::endl;
	try{
		Bureaucrat	max;		
		Form		form("constitution", 1, 15);			
		Form		form1(form);			
		std::cout << max << std::endl;
		std::cout << form << std::endl;
		std::cout << form1 << std::endl;
		max.signForm(form);
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "\n\n---LOW GRADE---" << std::endl;
	try{
		Bureaucrat	max("Maxi", 13);
		Form		form("constitution", 1, 15);			
		max.signForm(form);
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n---CONSTRUCTION FAIL---" << std::endl;
	try{
		Bureaucrat	max("Maxi", 13);
		Form		form("constitution", -1, 15);			
		std::cout << form << std::endl;
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n---CONSTRUCTION FAIL2---" << std::endl;
	try{
		Bureaucrat	max("Maxi", 13);
		Form		form("constitution", 11, 151);			
		std::cout << form << std::endl;
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << "\n\nEnd of main." << std::endl;

}