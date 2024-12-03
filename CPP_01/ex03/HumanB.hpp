/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:43:51 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/09 13:10:00 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string		_name;
	const Weapon	*_weapon;
public:
	HumanB(const std::string& name);
	~HumanB();
	void	attack(void);
    void    setWeapon(const Weapon& weapon);
};


#endif