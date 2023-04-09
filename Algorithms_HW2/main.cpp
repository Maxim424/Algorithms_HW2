#include "Executors/ordinary_executor.h"
#include "Utilities/string_generator.h"

int main() {
    std::ofstream fout;
    std::string text;
    std::string text2 = get_random_string(100000, 2);
    std::string text4 = get_random_string(100000, 4);

    text = text2.substr(0, 10000);
    execute_ordinarily(fout, text, 2);
    fout.close();

    text = text4.substr(0, 10000);
    execute_ordinarily(fout, text, 4);
    fout.close();

    text = text2;
    execute_ordinarily(fout, text, 2);
    fout.close();

    text = text4;
    execute_ordinarily(fout, text, 4);
    fout.close();
}
