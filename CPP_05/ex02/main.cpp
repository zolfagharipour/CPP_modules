/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 14:10:51 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{	
	std::cout << "---NO EXCEPTION---" << std::endl;
	try{
		Bureaucrat				alex("Alex", 1);
		ShrubberyCreationForm	shrub("Shrub");
		ShrubberyCreationForm	shrub1(shrub);
		ShrubberyCreationForm	shrub2 = shrub1;
		
		RobotomyRequestForm		robot("Robot");
		RobotomyRequestForm		robot1(robot);
		RobotomyRequestForm		robot2 = robot1;

		PresidentialPardonForm	pres("Pres");
		PresidentialPardonForm	pres1(pres);
		PresidentialPardonForm	pres2 = pres1;

		std::cout << "\n\n\n";
		alex.signForm(shrub);
		alex.executeForm(shrub);

		std::cout << "\n\n\n";
		alex.signForm(robot);
		alex.executeForm(robot);

		std::cout << "\n\n\n";
		alex.signForm(pres);
		alex.executeForm(pres);
		
		std::cout << "\n\n\n";
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << "\n\n---SOME EXCEPTION---" << std::endl;
	try{
		Bureaucrat 				max;
		
		Bureaucrat 				bob("Bob", 146);
		ShrubberyCreationForm	shrub("Shrub");
		RobotomyRequestForm		robot("Robot");
		PresidentialPardonForm	pres("Pres");
		
		std::cout << "\n\n\n";
		bob.signForm(shrub);
		max.signForm(shrub);
		bob.executeForm(shrub);
		
		std::cout << "\n\n\n";
		bob.signForm(robot);
		max.signForm(robot);
		bob.executeForm(robot);

		std::cout << "\n\n\n";
		bob.signForm(pres);
		max.signForm(pres);
		bob.executeForm(pres);
		
		std::cout << "\n\n\n";
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\nEnd of main." << std::endl;

}