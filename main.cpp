#include <iostream>
#include "vector"
#include "format"



int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);

    for (int i = 0; i < main_args.size(); i++)
        std::cout << std::format("Argument {}: {}", std::to_string(i), main_args[i]) << std::endl;

    return 0;
}