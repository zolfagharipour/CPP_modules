/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:23:29 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/09 12:45:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& name)
{
	_type = name;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void) const
{
	const std::string& ref = _type;
	return (ref);
}

void	Weapon::setType(const std::string& name)
{
	_type = name;
}
