//
// Created by Максим Кузнецов on 09.04.2023.
//

#include <vector>
#include "kmp.h"

int kmp_brs_find(std::string &text, std::string &pattern) {
    int last_position = 0;
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
            last_position = i - m + 1;
//            std::cout << "[kmp_brs] Pattern found at position " << i - m + 1 << "\n";
        }
    }
    return last_position;
}

int kmp_br_find(std::string &text, std::string &pattern) {
    int last_position = 0;
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
            last_position = i - m + 1;
//            std::cout << "[kmp_br] Pattern found at position " << i - m + 1 << "\n";
        }
    }
    return last_position;
}

// Works.
int kmp_br_find_additional_2(std::string &text, std::string &original_pattern, std::vector<int> &char_position) {
    std::string pattern(original_pattern);
    const std::string charset[] = {"a", "b", "c", "d"};
    int last_position = 0;
    if (char_position.size() == 1) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            int position = kmp_br_find(text, pattern);
            if (position > last_position) {
                last_position = position;
            }
//            std::cout << "[kmp_br_additional_2] Pattern found at position " << last_position << "\n";
        }
    } else if (char_position.size() == 2) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                int position = kmp_br_find(text, pattern);
                if (position > last_position) {
                    last_position = position;
                }
//                std::cout << "[kmp_br_additional_2] Pattern found at position " << last_position << "\n";
            }
        }
    } else if (char_position.size() == 3) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 2; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    int position = kmp_br_find(text, pattern);
                    if (position > last_position) {
                        last_position = position;
                    }
//                    std::cout << "[kmp_br_additional_2] Pattern found at position " << last_position << "\n";
                }
            }
        }
    } else if (char_position.size() == 4) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 2; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    for (int l = 0; l < 2; ++l) {
                        pattern.replace(char_position[3], 1, charset[l]);
                        int position = kmp_br_find(text, pattern);
                        if (position > last_position) {
                            last_position = position;
                        }
//                        std::cout << "[kmp_br_additional_2] Pattern found at position " << last_position << "\n";
                    }
                }
            }
        }
    }
    return last_position;
}


// Works.
int kmp_brs_find_additional_2(std::string &text, std::string &original_pattern, std::vector<int> &char_position) {
    const std::string charset[] = {"a", "b", "c", "d"};
    std::string pattern(original_pattern);
    int last_position = 0;
    if (char_position.size() == 1) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            int position = kmp_brs_find(text, pattern);
            if (position > last_position) {
                last_position = position;
            }
//            std::cout << "[kmp_brs_additional_2] Pattern found at position " << last_position << "\n";
        }
    } else if (char_position.size() == 2) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                int position = kmp_brs_find(text, pattern);
                if (position > last_position) {
                    last_position = position;
                }
//                std::cout << "[kmp_brs_additional_2] Pattern found at position " << last_position << "\n";
            }
        }
    } else if (char_position.size() == 3) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 2; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    int position = kmp_brs_find(text, pattern);
                    if (position > last_position) {
                        last_position = position;
                    }
//                    std::cout << "[kmp_brs_additional_2] Pattern found at position " << last_position << "\n";
                }
            }
        }
    } else if (char_position.size() == 4) {
        for (int i = 0; i < 2; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 2; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 2; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    for (int l = 0; l < 2; ++l) {
                        pattern.replace(char_position[3], 1, charset[l]);
                        int position = kmp_brs_find(text, pattern);
                        if (position > last_position) {
                            last_position = position;
                        }
//                        std::cout << "[kmp_brs_additional_2] Pattern found at position " << last_position << "\n";
                    }
                }
            }
        }
    }
    return last_position;
}


// Works.
int kmp_br_find_additional_4(std::string &text, std::string &original_pattern, std::vector<int> &char_position) {
    const std::string charset[] = {"a", "b", "c", "d"};
    std::string pattern(original_pattern);
    int last_position = 0;
    if (char_position.size() == 1) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            int position = kmp_br_find(text, pattern);
            if (position > last_position) {
                last_position = position;
            }
//            std::cout << "[kmp_br_additional_4] Pattern found at position " << last_position << "\n";
        }
    } else if (char_position.size() == 2) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                int position = kmp_br_find(text, pattern);
                if (position > last_position) {
                    last_position = position;
                }
//                std::cout << "[kmp_br_additional_4] Pattern found at position " << last_position << "\n";
            }
        }
    } else if (char_position.size() == 3) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 4; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    int position = kmp_br_find(text, pattern);
                    if (position > last_position) {
                        last_position = position;
                    }
//                    std::cout << "[kmp_br_additional_4] Pattern found at position " << last_position << "\n";
                }
            }
        }
    } else if (char_position.size() == 4) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 4; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    for (int l = 0; l < 4; ++l) {
                        pattern.replace(char_position[3], 1, charset[l]);
                        int position = kmp_br_find(text, pattern);
                        if (position > last_position) {
                            last_position = position;
                        }
//                        std::cout << "[kmp_br_additional_4] Pattern found at position " << last_position << "\n";
                    }
                }
            }
        }
    }
    return last_position;
}

// Works.
int kmp_brs_find_additional_4(std::string &text, std::string &original_pattern, std::vector<int> &char_position) {
    const std::string charset[] = {"a", "b", "c", "d"};
    std::string pattern(original_pattern);
    int last_position = 0;
    if (char_position.size() == 1) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            int position = kmp_brs_find(text, pattern);
            if (position > last_position) {
                last_position = position;
            }
//            std::cout << "[kmp_brs_additional_4] Pattern found at position " << last_position << "\n";
        }
    } else if (char_position.size() == 2) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                int position = kmp_brs_find(text, pattern);
                if (position > last_position) {
                    last_position = position;
                }
//                std::cout << "[kmp_brs_additional_4] Pattern found at position " << last_position << "\n";
            }
        }
    } else if (char_position.size() == 3) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 4; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    int position = kmp_brs_find(text, pattern);
                    if (position > last_position) {
                        last_position = position;
                    }
//                    std::cout << "[kmp_brs_additional_4] Pattern found at position " << last_position << "\n";
                }
            }
        }
    } else if (char_position.size() == 4) {
        for (int i = 0; i < 4; ++i) {
            pattern.replace(char_position[0], 1, charset[i]);
            for (int j = 0; j < 4; ++j) {
                pattern.replace(char_position[1], 1, charset[j]);
                for (int k = 0; k < 4; ++k) {
                    pattern.replace(char_position[2], 1, charset[k]);
                    for (int l = 0; l < 4; ++l) {
                        pattern.replace(char_position[3], 1, charset[l]);
                        int position = kmp_brs_find(text, pattern);
                        if (position > last_position) {
                            last_position = position;
                        }
//                        std::cout << "[kmp_brs_additional_4] Pattern found at position " << last_position << "\n";
                    }
                }
            }
        }
    }
    return last_position;
}