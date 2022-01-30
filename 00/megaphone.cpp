/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>

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
