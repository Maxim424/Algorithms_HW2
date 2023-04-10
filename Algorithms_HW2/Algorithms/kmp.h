//
// Created by Максим Кузнецов on 09.04.2023.
//

#ifndef ALGORITHMS_HW2_KMP_H
#define ALGORITHMS_HW2_KMP_H

#include <iostream>
#include <string>

int kmp_br_find(std::string &text, std::string &pattern);

int kmp_brs_find(std::string &text, std::string &pattern);

int kmp_br_find_additional_2(std::string &text, std::string &pattern, std::vector<int> &char_position);

int kmp_brs_find_additional_2(std::string &text, std::string &pattern, std::vector<int> &char_position);

int kmp_br_find_additional_4(std::string &text, std::string &pattern, std::vector<int> &char_position);

int kmp_brs_find_additional_4(std::string &text, std::string &pattern, std::vector<int> &char_position);


#endif //ALGORITHMS_HW2_KMP_H
