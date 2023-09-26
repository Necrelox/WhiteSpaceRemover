//
// Created by ruby on 25/09/2023.
//

#ifndef WHITESPACEREMOVER_PATHPROCESSOR_HPP
#define WHITESPACEREMOVER_PATHPROCESSOR_HPP

#include "interfaces/IPathProcessor.hpp"

class PathProcessor: public IPathProcessor {
public:
    PathProcessor() = default;

    ~PathProcessor() = default;

    [[nodiscard]] PathType getPathType(const std::string &path) const override;

    [[nodiscard]] bool isFile(const std::string &path) const override;

    [[nodiscard]] bool isDirectory(const std::string &path) const override;
};

#endif //WHITESPACEREMOVER_PATHPROCESSOR_HPP
