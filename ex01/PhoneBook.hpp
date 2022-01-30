/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <algorithm>

#include "Contact.hpp"

#define MAX_ERROR_INPUT 3
#define MAX_NUMBER_CONTACTS 8
#define CONTACT_INPUTS 5
#define NUMBER_COLUMNS 4
#define MAX_COLUMN_WIDTH 10

class PhoneBook {
 public:
        Contact contacts[MAX_NUMBER_CONTACTS];
        void    add_contact();
        void    search_contact();
};

#endif  // PHONEBOOK_HPP
