/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:15:38 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/14 15:49:14 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main()
{
	std::cout << "--CONSTRUCTION CHECKS--" << std::endl;
	Ice		ice;
	Ice		ice1(ice);
	Ice		ice2 = ice1;
	Cure	cure;
	Cure	cure1(cure);
	Cure	cure2 = cure1;

	Character	bob("boby");
	Character	bob1(bob);
	Character	bob2 = bob1;

	MateriaSource	materia;
	
	std::cout << "--MATERIASOURCE CHECKS--" << std::endl;
	
	AMateria*	iceNew = new Cure();
	AMateria*	cureNew = new Cure();
	
	materia.learnMateria(iceNew);
	materia.learnMateria(cureNew);

	bob.equip(materia.createMateria("ice"));
	bob.equip(materia.createMateria("cure"));

	bob.unequip(1);
	bob.unequip(2);
	{
		
		std::cout << "\n--ORIGINAL MAIN--\n" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
		
}