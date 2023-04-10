#include "Executors/ordinary_executor.h"
#include "Utilities/string_generator.h"
#include "Executors/additional_char_executor.h"
#include "Algorithms/naive.h"
#include "Algorithms/kmp.h"

void test() {
    std::vector<int> char_position;
    int char_count = 2;
    for (int i = 1; i <= char_count; ++i) {
        char_position.push_back(i * 2);
    }
    std::string text = get_random_string(30, 2);
    std::string pattern = text.substr(9, 10);
    for (int j = 0; j < char_count; ++j) {
        std::string str = "?";
        pattern.replace(char_position[j], 1, str);
    }
    std::cout << "[pattern] " << pattern << "\n";
    int last_position = naive_find_additional_char(text, pattern);
    std::cout << "[test] position " << last_position << " ";
    for (int i = last_position; i < last_position + pattern.size(); ++i) {
        if (pattern[i - last_position] == '?') {
            continue;
        }
        if (text[i] != pattern[i - last_position]) {
            std::cout << "false\n";
            std::cout << "[text] " << text << "\n";
            std::cout << "[pattern] " << pattern << "\n";
            std::cout << i << " " << text[i] << " " << pattern[i] << "\n";
            return;
        }
    }
    std::cout << "true\n";
}

int main() {
    test();


    std::ofstream fout;
    std::string text;
    std::string text2 = get_random_string(100000, 2);
    std::string text4 = get_random_string(100000, 4);

    text = text2.substr(0, 10000);
    execute_ordinarily(fout, text, 2);
    execute_with_additional_char(fout, text, 2, 1);
    execute_with_additional_char(fout, text, 2, 2);
    execute_with_additional_char(fout, text, 2, 3);
    execute_with_additional_char(fout, text, 2, 4);

    text = text4.substr(0, 10000);
    execute_ordinarily(fout, text, 4);
    execute_with_additional_char(fout, text, 4, 1);
    execute_with_additional_char(fout, text, 4, 2);
    execute_with_additional_char(fout, text, 4, 3);
    execute_with_additional_char(fout, text, 4, 4);

    text = text2;
    execute_ordinarily(fout, text, 2);
    execute_with_additional_char(fout, text, 2, 1);
    execute_with_additional_char(fout, text, 2, 2);
    execute_with_additional_char(fout, text, 2, 3);
    execute_with_additional_char(fout, text, 2, 4);

    text = text4;
    execute_ordinarily(fout, text, 4);
    execute_with_additional_char(fout, text, 4, 1);
    execute_with_additional_char(fout, text, 4, 2);
    execute_with_additional_char(fout, text, 4, 3);
    execute_with_additional_char(fout, text, 4, 4);
}
