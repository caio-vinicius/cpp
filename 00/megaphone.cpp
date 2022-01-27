/* ************************************************************************** */
/*                                                                            */
/*   Copyright (c) 2022 Caio Souza. All rights reserved.                      */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:28:58 by csouza-f          #+#    #+#             */
/*   Updated: 2022/01/27 20:41:06 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copyright 2022 Caio Souza

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    (void)argc;
    std::string voice;
    for (unsigned int i = 1; argv[i]; i++)
        voice += argv[i];
    if (!voice.empty()) {
        for (unsigned int i = 0; i < voice.length(); i++)
            voice[i] = std::toupper(voice[i]);
    } else {
        voice = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    std::cout << voice;
    return (0);
}
