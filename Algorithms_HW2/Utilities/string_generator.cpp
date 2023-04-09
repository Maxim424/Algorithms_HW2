//
// Created by Максим Кузнецов on 09.04.2023.
//

#include "string_generator.h"

std::string get_random_string(size_t length, int alphabet_size)
{
    srand(time(nullptr));
    if (alphabet_size > 26 || alphabet_size < 0) {
        alphabet_size = 26;
    }
    auto randchar = [alphabet_size]() -> char
    {
        const char charset[] = "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = alphabet_size;
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}