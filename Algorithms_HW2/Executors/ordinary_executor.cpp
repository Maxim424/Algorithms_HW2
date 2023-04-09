//
// Created by Максим Кузнецов on 09.04.2023.
//

#include <iostream>
#include "ordinary_executor.h"
#include "../Algorithms/naive.h"
#include "../Algorithms/kmp.h"

void execute_naive(std::ofstream &fout, std::string &text, std::string &pattern) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        naive_find(text, pattern);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_kmp_br(std::ofstream &fout, std::string &text, std::string &pattern) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        kmp_br_find(text, pattern);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_kmp_brs(std::ofstream &fout, std::string &text, std::string &pattern) {
    auto *m = new std::chrono::nanoseconds[10];
    for (int k = 0; k < 10; ++k) {
        auto start = std::chrono::high_resolution_clock::now();
        kmp_brs_find(text, pattern);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        m[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    }
    std::chrono::nanoseconds sum = {};
    for (int k = 0; k < 10; ++k) {
        sum += m[k];
    }
    fout << (sum / 10).count() << ";";
}

void execute_ordinarily(std::ofstream &fout, std::string &text, int alphabet_size) {
    std::string file_name = "../../ordinary/219_КузнецовМВ_output_" +
            std::to_string(alphabet_size) + "_" +
            std::to_string(text.size()) + ".csv";
    fout.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc);
    fout << ";naive;KMP-br;KMP-brs;\n";
    std::string pattern;
    for (int i = 100; i <= 3000; i += 100) {
        fout << i << ";";
        pattern = text.substr(5000, i);
        execute_naive(fout, text, pattern);
        execute_kmp_br(fout, text, pattern);
        execute_kmp_brs(fout, text, pattern);
        fout << "\n";
    }
}
