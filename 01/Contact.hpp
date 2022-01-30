/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:53:19 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/29 17:45:22 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
    public:
        Contact(std::string _first_name,
                std::string _last_name,
                std::string _nickname,
                std::string _phone_number,
                std::string _darkest_secret)
        {
            first_name = _first_name;
            last_name = _last_name;
            nickname = _nickname;
            phone_number = _phone_number;
            darkest_secret = _darkest_secret;
        }
        Contact() {};
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};
