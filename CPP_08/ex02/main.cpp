/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:43:11 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 14:24:42 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "---MUTANTSTACK---" << std::endl;
		MutantStack<int>	OrigMstack;
		MutantStack<int>	SecondMstack = OrigMstack;
		MutantStack<int>	mstack(SecondMstack);
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		MutantStack<int>	LastMstack = mstack;
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\n---LIST---\n (outcome has to be same as above)" << std::endl;
		std::list<int>	list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// std::stack<int> s(list);
	}
	{
		std::cout << "\n\n---MY TEST STRING---" << std::endl;
		
		
		MutantStack<std::string>	mstack;
		mstack.push("Hello");
		mstack.push("World");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\n\n---MY TEST REVERSE---" << std::endl;
		
		
		MutantStack<char>	mstack;
		mstack.push('d');
		mstack.push('l');
		mstack.push('r');
		mstack.push('o');
		mstack.push('W');
		mstack.push(' ');
		mstack.push('o');
		mstack.push('l');
		mstack.push('l');
		mstack.push('e');
		mstack.push('H');
		MutantStack<char>::reverse_iterator it = mstack.rbegin();
		MutantStack<char>::reverse_iterator ite = mstack.rend();
		while (it != ite)
		{
			std::cout << *it;
			++it;
		}
		std::cout << std::endl;
	}
}