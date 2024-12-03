/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:27:41 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/14 11:14:06 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{	
	try{
		AForm*		form = NULL;
		Intern		alex;
		std::cout << "\n\n\n";
		
		form = alex.makeForm("shrubbery creation", "Shrub");
		std::cout << *form << std::endl;
		delete form;
		std::cout << "\n\n\n";
		
		form = alex.makeForm("robotomy request", "Robot");
		std::cout << *form << std::endl;
		delete form;
		std::cout << "\n\n\n";
		
		form = alex.makeForm("presidential pardon", "Pres");
		std::cout << *form << std::endl;
		delete form;
		std::cout << "\n\n\n";

		form = alex.makeForm("tax evasion", "Tax");
		std::cout << "\n\n\n";
	}
	catch ( const std::exception& e ){
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\nEnd of main." << std::endl;

}