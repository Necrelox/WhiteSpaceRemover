//
// Created by ruby on 26/09/2023.
//

#include <string>
#include "SpaceRemover.hpp"

int SpaceRemover::removeSpaces(std::string &line) const {
    int count = 0;
    while (!line.empty() && line[line.size() - 1] == ' ') {
        line.pop_back();
        count++;
    }
    return count;
}
