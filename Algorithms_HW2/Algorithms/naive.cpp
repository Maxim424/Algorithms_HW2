//
// Created by Максим Кузнецов on 09.04.2023.
//

#include "naive.h"

void naive_find(std::string &text, std::string &pattern) {
    int n = static_cast<int>(text.length());
    int m = static_cast<int>(pattern.length());
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            std::cout << "[naive] Pattern found at position " << i << "\n";
        }
    }
}