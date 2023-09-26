//
// Created by ruby on 26/09/2023.
//

#ifndef WHITESPACEREMOVER_ISPACEREMOVER_HPP
#define WHITESPACEREMOVER_ISPACEREMOVER_HPP

class ISpaceRemover {
public:
    virtual int removeSpaces(std::string &line) const = 0;
};

#endif //WHITESPACEREMOVER_ISPACEREMOVER_HPP
