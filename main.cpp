#include <regex>
#include <iostream>
#include "WhiteSpaceRemover.hpp"

int main(int ac, char **av) {
    if (ac != 2)
        return -1;
    try {
        std::string path = av[1];
        WhiteSpaceRemover remover(path, true, std::regex(".*"));
        std::cout << "Total spaces removed : " << remover.run() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
