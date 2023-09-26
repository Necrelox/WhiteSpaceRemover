//
// Created by ruby on 26/09/2023.
//

#ifndef WHITESPACEREMOVER_IDIRECTORYREADER_HPP
#define WHITESPACEREMOVER_IDIRECTORYREADER_HPP

class IDirectoryReader {
public:
    [[nodiscard]] virtual std::vector<std::string> getFilesFromDirectory(const std::string &path, bool recursive, const std::regex& regex) const = 0;
};

#endif //WHITESPACEREMOVER_IDIRECTORYREADER_HPP
