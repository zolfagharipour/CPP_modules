/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:51:35 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/12/03 18:40:58 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {  
        for (int i = 1; i < ac; i++)
        {
            std::string arg(av[i]);
            for (size_t j = 0; j < arg.length(); j++)
                arg[j] =  std::toupper (static_cast<unsigned char> (arg[j]));
            std::cout << arg << ' ';
        }
        std::cout << std::endl;
    }
}
