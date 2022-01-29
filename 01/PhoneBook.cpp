/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:25:34 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/29 11:58:55 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phonebook;
    Contact new_contact("caio", "souza", "csouza-f", "000000000", "like eat soap");

    phonebook.add_contact(new_contact); 
    phonebook.search_contact(); 
    return (0);
}
