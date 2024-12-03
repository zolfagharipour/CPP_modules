/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:44:13 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/04 15:55:48 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
    const Animal* animal = new Animal();
    std::cout << "TYPE: " << animal->getType() << '\n';
    std::cout << "SOUND: ";
    animal->makeSound();
    delete animal;    
    std::cout << "--------------------------" << std::endl;
    
    
    const Animal* cat = new Cat();
    std::cout << "TYPE: " << cat->getType() << '\n';
    std::cout << "SOUND: ";
    cat->makeSound();
    delete cat;    
    std::cout << "--------------------------" << std::endl;
    

    const Animal* dog = new Dog();
    std::cout << "TYPE: " << dog->getType() << '\n';
    std::cout << "SOUND: ";
    dog->makeSound();
    delete dog;    
    std::cout << "--------------------------" << std::endl;
    


    const WrongAnimal* wAnimal = new WrongAnimal();
    std::cout << "TYPE: " << wAnimal->getType() << '\n';
    std::cout << "SOUND: ";
    wAnimal->makeSound();
    delete wAnimal;    
    std::cout << "--------------------------" << std::endl;
    

    const WrongAnimal* wCat = new WrongCat();
    std::cout << "TYPE: " << wCat->getType() << '\n';
    std::cout << "SOUND: ";
    wCat->makeSound();
    delete wCat;    
    std::cout << "--------------------------" << std::endl;
    

}

