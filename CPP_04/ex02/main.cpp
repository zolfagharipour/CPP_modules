/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:44:13 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/15 12:39:41 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
    // Animal  tmp;
    Animal*     animals[10];
    
    std::cout << "-------Constructing-------\n";
    
    for (int i = 0; i < 5; i++)
    {
        animals[i] = new Cat();
    }
    for (int j = 5; j < 10; j++)
    {
        animals[j] = new Dog();
    }
    
    std::cout << "\n-------TESTING-------\n";
    
    std::cout << animals[0]->getType() << '\n';
    animals[0]->makeSound();
    std::cout << animals[5]->getType() << '\n';
    animals[5]->makeSound();
    
    std::cout << "\n-------Deconstructing-------\n";

    
    for (int k = 0; k < 10; k++)
    {
        delete animals[k];
    }
    
    std::cout << "\n-------DeepCopy-------\n";

    Cat* cat = new Cat;
    Cat tmp1 = *cat;
    Cat tmp2(*cat);
    
    std::cout << "First cat idea #1\t" << cat->getIdea(0) << '\n';
    std::cout << "tmp1 cat idea #1\t" << tmp1.getIdea(0) << '\n';
    std::cout << "tmp2 cat idea #1\t" << tmp2.getIdea(0) << '\n';
    
    cat->steIdea(0, "learn CPP");
    tmp1.steIdea(0, "learn Classes");
    tmp2.steIdea(0, "learn Polymorphism");
    
    std::cout << "First cat idea #1\t" << cat->getIdea(0) << '\n';
    std::cout << "tmp1 cat idea #1\t" << tmp1.getIdea(0) << '\n';
    std::cout << "tmp2 cat idea #1\t" << tmp2.getIdea(0) << '\n';

    delete cat;
}

