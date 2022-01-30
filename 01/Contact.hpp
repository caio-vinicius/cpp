/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#ifndef CONTACTL_HPP
#define CONTACTL_HPP

#include <iostream>
#include <string>

class Contact {
 public:
        Contact(std::string _first_name,
                std::string _last_name,
                std::string _nickname,
                std::string _phone_number,
                std::string _darkest_secret) {
            first_name = _first_name;
            last_name = _last_name;
            nickname = _nickname;
            phone_number = _phone_number;
            darkest_secret = _darkest_secret;
        }
        Contact() {}
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif  // CONTACT_HPP
