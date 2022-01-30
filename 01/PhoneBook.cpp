/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.hpp"

void    phonebook_usage(void) {
    std::cout << std::endl << "Usage:\n\nHELP\tDisplay this output message" << \
    std::endl << "ADD\tAdd a new contact" << std::endl << \
    "SEARCH\tDisplay all contacts" << std::endl;
}

int main(void) {
    PhoneBook phonebook;
    std::string input;
    unsigned int i;

    i = 0;
    std::cout << \
    "Welcome to Phonebook. To view available commands, type HELP." << std::endl;
    while (std::cout << "Phonebook> " && std::getline(std::cin, input)) {
        if (input == "HELP" || input == "help") {
            phonebook_usage();
        } else if (input == "ADD" || input == "add") {
            phonebook.add_contact();
        } else if (input == "SEARCH" || input == "search") {
            phonebook.search_contact();
        } else if (input == "EXIT" || input == "exit" || input == "quit" || \
                    input == "e" || input == "q") {
            break;
        } else {
            std::cout << "Error: Command not found." << std::endl;
            i++;
            if (i == MAX_ERROR_INPUT) {
                i = 0;
                phonebook_usage();
            }
            continue;
        }
        i = 0;
    }
    return (0);
}
