//
// Created by Максим Кузнецов on 10.04.2023.
//

#include <iostream>
#include "additional_char_executor.h"
#include "../Algorithms/naive.h"
#include "../Algorithms/kmp.h"

void execute_naive_additional_char(std::ofstream &fout, std::string &text, std::string &pattern) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        naive_find_additional_char(text, pattern);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_kmp_br_additional_char(std::ofstream &fout, std::string &text, std::string &pattern, int alphabet_size, std::vector<int> &char_position) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        if (alphabet_size == 2) {
            kmp_br_find_additional_2(text, pattern, char_position);
        } else if (alphabet_size == 4) {
            kmp_br_find_additional_4(text, pattern, char_position);
        }
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_kmp_brs_additional_char(std::ofstream &fout, std::string &text, std::string &pattern, int alphabet_size, std::vector<int> &char_position) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        if (alphabet_size == 2) {
            kmp_brs_find_additional_2(text, pattern, char_position);
        } else if (alphabet_size == 4) {
            kmp_brs_find_additional_4(text, pattern, char_position);
        }
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_with_additional_char(std::ofstream &fout, std::string &text, int alphabet_size, int char_count) {
    std::vector<int> char_position;
    for (int i = 1; i <= char_count; ++i) {
        char_position.push_back(i * 15);
    }
    std::cout << "Text example\n";
    std::cout << text.substr(0, 10) << "\n";

    std::string file_name = "../../additional_char/219_КузнецовМВ_output_" +
                            std::to_string(alphabet_size) + "_" +
                            std::to_string(text.size()) + "_" +
                            std::to_string(char_count) + ".csv";
    std::cout << file_name << "\n";
    fout.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc);
    fout << ";naive;KMP-br;KMP-brs;\n";
    std::string pattern;
    for (int i = 100; i <= 3000; i += 100) {
        fout << i << ";";
        pattern = text.substr(5000, i);
        for (int j = 0; j < char_count; ++j) {
            std::string str = "?";
            pattern.replace(char_position[j], 1, str);
        }
        if (pattern.size() == 100) {
            std::cout << pattern << "\n";
        }

        execute_naive_additional_char(fout, text, pattern);
        execute_kmp_br_additional_char(fout, text, pattern, alphabet_size, char_position);
        execute_kmp_brs_additional_char(fout, text, pattern, alphabet_size, char_position);
        fout << "\n";
    }
    fout.close();
}