//
// Created by ruby on 25/09/2023.
//

#ifndef WHITESPACEREMOVER_DIRECTORYREADER_HPP
#define WHITESPACEREMOVER_DIRECTORYREADER_HPP

#include "interfaces/IDirectoryReader.hpp"

class DirectoryReader: public IDirectoryReader {
public:
    DirectoryReader() = default;

    ~DirectoryReader() = default;

    [[nodiscard]] std::vector<std::string> getFilesFromDirectory(
            const std::string &path, bool recursive,
            const std::regex& regex) const override;

    [[nodiscard]] std::vector<std::string> getFilesFromDirectory(
            const std::string &path) const {
        return getFilesFromDirectory(path, false, std::regex(".*"));
    }
};

#endif //WHITESPACEREMOVER_DIRECTORYREADER_HPP
