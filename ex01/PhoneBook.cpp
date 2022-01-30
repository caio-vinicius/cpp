/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.hpp"

int ft_isnumeric(std::string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return (0);
    }
    return (1);
}

void PhoneBook::search_contact() {
    std::string columns[NUMBER_COLUMNS] = {"index",
                                           "first name",
                                           "last name",
                                           "nickname"};
    std::cout << "|";
    for (unsigned int i = 0; i < NUMBER_COLUMNS; i++) {
        std::cout << std::setw(MAX_COLUMN_WIDTH) << columns[i] << "|";
    }
    for (unsigned int i = 0; i < MAX_NUMBER_CONTACTS; i++) {
        std::cout << std::endl << "|";
        std::cout << std::setw(MAX_COLUMN_WIDTH) << i << "|";
        std::string values[NUMBER_COLUMNS - 1] = {contacts[i].first_name,
                                                  contacts[i].last_name,
                                                  contacts[i].nickname};
        for (unsigned int i = 0; i < NUMBER_COLUMNS - 1; i++) {
            if (values[i].length() >= MAX_COLUMN_WIDTH) {
                values[i] = values[i].substr(0, MAX_COLUMN_WIDTH - 1) + ".";
            }
            std::cout << std::setw(MAX_COLUMN_WIDTH) << values[i] << "|";
        }
    }
    std::cout << std::endl;
    std::string input;
    while (std::cout << "> SEARCH: Enter index: " && \
            std::getline(std::cin, input)) {
        if (input == "EXIT" || input == "exit" || input == "quit" || \
            input == "e" || input == "q")
            break;
        if (input == "add" || input == "search" || input == "ADD" || \
            input == "SEARCH") {
            std::cout << \
                "Error: Type EXIT to go back to Phonebook." << std::endl;
            continue;
        }
        if (!ft_isnumeric(input)) {
            std::cout << "Error: Must be a positive number." << std::endl;
            continue;
        }
        int contact_index = std::atoi(input.c_str());
        if (contact_index >= MAX_NUMBER_CONTACTS) {
            std::cout << "Error: Index out of range." << std::endl;
            continue;
        }
        std::string contact_keys[CONTACT_INPUTS] = {"First name",
                                                    "Last name",
                                                    "Nickname",
                                                    "Phone number",
                                                    "Darkest secret"};
        if (contacts[contact_index].first_name.empty()) {
            std::cout << "Error: Index's contact is empty." << std::endl;
            continue;
        }
        std::string contact_values[CONTACT_INPUTS] = {
                                        contacts[contact_index].first_name,
                                        contacts[contact_index].last_name,
                                        contacts[contact_index].nickname,
                                        contacts[contact_index].phone_number,
                                        contacts[contact_index].darkest_secret};
        for (unsigned int i = 0; i < CONTACT_INPUTS; i++) {
            std::cout << contact_keys[i] + ": " << \
                contact_values[i] << std::endl;
        }
    }
}

void PhoneBook::add_contact() {
    static unsigned int i;
    std::string values[CONTACT_INPUTS];
    std::string questions[CONTACT_INPUTS] = {"First name",
                                            "Last name",
                                            "Nickname",
                                            "Phone number",
                                            "Darkest secret"};

    for (unsigned int i = 0; i < CONTACT_INPUTS; i++) {
        while (1) {
            std::cout << "> ADD: Enter `" + questions[i] + "`: ";
            std::getline(std::cin, values[i]);
            if (values[i].empty()) {
                std::cout << "Error: Must fill the field." << std::endl;
                continue;
            } else {
                break;
            }
        }
    }
    Contact new_contact(values[0], values[1], values[2], values[3], values[4]);
    if (i == MAX_NUMBER_CONTACTS)
        i = 0;
    contacts[i] = new_contact;
    std::cout << \
        "Success: Contact `" + contacts[i].first_name + "` added." << std::endl;
    i++;
}

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
