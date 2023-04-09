//
// Created by Максим Кузнецов on 09.04.2023.
//

#include "kmp.h"

void kmp_brs_find(std::string &text, std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    std::vector<int> br(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && k < m && pattern[k] != pattern[i]) {
            k = br[k - 1];
        }
        if (k < m && pattern[k] == pattern[i]) {
            ++k;
        }
        br[i] = k;
    }
    std::vector<int> brs(m, 0);
    for (int i = 0; i < m - 1; ++i) {
        if (br[i + 1] > br[i]) {
            if (br[i] - 1 >= 0) {
                brs[i] = brs[br[i] - 1];
            } else {
                brs[i] = 0;
            }

        } else {
            brs[i] = br[i];
        }
    }
    brs[m - 1] = br[m - 1];
    int kol = 0;
    for (int i = 0; i < n; ++i) {
        while (kol > 0 && kol < m && pattern[kol] != text[i]) {
            kol = brs[kol - 1];
        }
        if (kol < m && pattern[kol] == text[i]) {
            ++kol;
        }
        if (kol == m) {
            kol = brs[kol - 1];
//            std::cout << "[kmp_brs] Pattern found at position " << i - m + 1 << "\n";
        }
    }
}

void kmp_br_find(std::string &text, std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    std::vector<int> br(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && k < m && pattern[k] != pattern[i]) {
            k = br[k - 1];
        }
        if (k < m && pattern[k] == pattern[i]) {
            ++k;
        }
        br[i] = k;
    }
    int kol = 0;
    for (int i = 0; i < n; ++i) {
        while (kol > 0 && kol < m && pattern[kol] != text[i]) {
            kol = br[kol - 1];
        }
        if (kol < m && pattern[kol] == text[i]) {
            ++kol;
        }
        if (kol == m) {
            kol = br[kol - 1];
//            std::cout << "[kmp_br] Pattern found at position " << i - m + 1 << "\n";
        }
    }
}