/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:28:32 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/23 13:26:08 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
    size_t  _index;
    Contact _contacts[8];
    void    _ShowContact(void);

public:
    PhoneBook();
    ~PhoneBook();

    void    AddContact(void);
    void	SearchContact(void);
};
