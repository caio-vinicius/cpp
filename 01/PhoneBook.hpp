/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:17:58 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/29 11:58:37 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

#define MAX_NUMBER_CONTACTS 8

class PhoneBook
{
    public:
        Contact contacts[MAX_NUMBER_CONTACTS];
        void    add_contact(Contact new_contact);
        void    search_contact();
};

void PhoneBook::search_contact()
{
    std::cout << "Searching..." << std::endl;
    for (unsigned int i = 0; i < MAX_NUMBER_CONTACTS; i++) {
        std::cout << contacts[i].first_name << std::endl;
    } 
}

void PhoneBook::add_contact(Contact new_contact)
{
    static unsigned int i;

    std::cout << "Adding..." << std::endl;
    if (i == MAX_NUMBER_CONTACTS)
        i = 0;
    contacts[i] = new_contact;
}
