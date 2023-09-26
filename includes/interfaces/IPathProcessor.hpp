//
// Created by ruby on 26/09/2023.
//

#ifndef WHITESPACEREMOVER_IPATHPROCESSOR_HPP
#define WHITESPACEREMOVER_IPATHPROCESSOR_HPP

class IPathProcessor {
public:
    enum class PathType {
        ABSOLUTE, RELATIVE, NOT_EXISTING
    };

    [[nodiscard]] virtual PathType getPathType(const std::string &path) const = 0;
    [[nodiscard]] virtual bool isFile(const std::string &path) const = 0;
    [[nodiscard]] virtual bool isDirectory(const std::string &path) const = 0;
};

#endif //WHITESPACEREMOVER_IPATHPROCESSOR_HPP
