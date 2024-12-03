/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:58 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/14 12:20:11 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>



Base* generate( void )
{
	std::srand(std::time(0));
	int		ran = std::rand() % 3;
	
	switch (ran)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (new Base);
	}
}

void	identify(Base* p)
{
	A*	a;
	B*	b;
	C*	c;

	
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Class A has been detected\t(with pointer)" << std::endl;
	else if (b)
		std::cout << "Class B has been detected\t(with pointer)" << std::endl;
	else if (c)
		std::cout << "Class C has been detected\t(with pointer)" << std::endl;
	else
		std::cout << "Cant identify." << std::endl;
}

void	identify(Base& p)
{
	try{
		A a = dynamic_cast<A&>(p);
		std::cout << "Class A has been detected\t(without pointer)" << std::endl;
		return ;
	}
	catch (const std::exception& e){}
	
	try{
		B	b = dynamic_cast<B&>(p);
		std::cout << "Class B has been detected\t(without pointer)" << std::endl;
		return ;
	}
	catch (const std::exception& e){}
	
	try{
		C	c = dynamic_cast<C&>(p);
		std::cout << "Class C has been detected\t(without pointer)" << std::endl;
		return ;
	}
	catch (const std::exception& e){}
	std::cout << "Cant identify." << std::endl;
}

int	main()
{
	Base* ptr;

	std::cout << "-----DETECTIN A-----\n";
	ptr = new A;
	identify(ptr);
	identify(*ptr);
	delete ptr;

	std::cout << "\n\n-----DETECTIN B-----\n";
	ptr = new B;
	identify(ptr);
	identify(*ptr);
	delete ptr;

	std::cout << "\n\n-----DETECTIN C-----\n";
	ptr = new C;
	identify(ptr);
	identify(*ptr);
	delete ptr;

	std::cout << "\n\n-----CHECKING FOR GENERATE-----\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "try " << i + 1 << std::endl;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		usleep (1000000);
	}
}
