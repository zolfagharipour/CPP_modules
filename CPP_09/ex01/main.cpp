/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:56:43 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 14:17:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	{
		if (ac != 2)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		std::string	input(av[1]);
		try{
			RPN			rpn(input);
			rpn.print();
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	// {
	// 	(void)av;
	// 	(void)ac;
	// 	try{
	// 		std::cout << "----THESE SHOULD WORK----" << std::endl;
			
	// 		RPN	rpn("8 9 * 9 - 9 - 9 - 4 - 1 +");
	// 		rpn.print();
			
	// 		RPN rpn1("7 7 * 7 -");
	// 		rpn1.print();

	// 		RPN rpn2("1 2 * 2 / 2 * 2 4 - +");
	// 		rpn2.print();
			
	// 		RPN rpn3("3 4 +");
	// 		rpn3.print();

	// 		RPN rpn4("5 1 2 + 4 * + 3 -");
	// 		rpn4.print();

	// 		RPN rpn5("9 2 / 3 *");
	// 		rpn5.print();

	// 		RPN rpn6("4 2 + 3 5 1 - * +");
	// 		rpn6.print();

	// 		RPN rpn7("7 2 3 * - 4 +");
	// 		rpn7.print();
			
	// 		RPN rpn8("9 3 1 - 3 * + 1 2 / +");
	// 		rpn8.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << "\n\n----ERROR DETECTION----" << std::endl;
	// 	try{
	// 		RPN	rpn("5 +");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("4 2 + 1");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("3 4 2 *");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("7 0 /");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("10 2 8 +");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("2 2 * *");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("+ 2 3");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
		
	// 	try{
	// 		RPN	rpn("3 a +");
	// 		rpn.print();
	// 	}
	// 	catch(std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
}
