#include "Executors/ordinary_executor.h"
#include "Utilities/string_generator.h"

int main() {
    std::ofstream fout;
    std::string text = get_random_string(10000, 2);
    execute_ordinarily(fout, text, 2);
}
