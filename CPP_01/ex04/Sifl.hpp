/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sifl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:15:43 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/14 10:47:04 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIFL_HPP
# define SIFL_HPP

# include <iostream>
# include <fstream>

struct Sifl
{
    std::ifstream	myFile;
	std::ofstream	newFile;
	std::string		fileName;
	std::string		read;
	std::string		s1;
	std::string		s2;
};


#endif