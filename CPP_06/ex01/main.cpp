/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:58 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/01 12:23:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{	
	Data	ptr;
	ptr.fourtytwo = 43;
	std::cout << "Original address of Data: " << &ptr << std::endl;

	uintptr_t	raw = Serializer::serialize(&ptr);
	std::cout << "Int address of Data: " << raw << std::endl;

	Data  *value;
	value = Serializer::deserialize(raw);
	std::cout << "New address of Data: " << value << std::endl;
	std::cout << "Value of fourtytwo: " << value->fourtytwo << std::endl;
}
