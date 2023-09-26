//
// Created by ruby on 25/09/2023.
//

#ifndef WHITESPACEREMOVER_SPACEREMOVER_HPP
#define WHITESPACEREMOVER_SPACEREMOVER_HPP

#include "interfaces/ISpaceRemover.hpp"

class SpaceRemover : public ISpaceRemover {
public:
    SpaceRemover() = default;

    ~SpaceRemover() = default;

    int removeSpaces(std::string &line) const override;
};

#endif //WHITESPACEREMOVER_SPACEREMOVER_HPP
