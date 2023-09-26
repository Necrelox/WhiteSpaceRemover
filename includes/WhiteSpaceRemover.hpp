//
// Created by ruby on 19/09/2023.
//

#ifndef WHITESPACEREMOVER_WHITESPACEREMOVER_HPP
#define WHITESPACEREMOVER_WHITESPACEREMOVER_HPP

#include "PathProcessor.hpp"
#include "SpaceRemover.hpp"
#include "DirectoryReader.hpp"

/**
 * @brief Class to remove white space from a file or a directory
 */
class WhiteSpaceRemover: public IDirectoryReader, public IPathProcessor, public ISpaceRemover {
private:
    std::string _path;
    std::regex _regex;
    bool _recursive;

    DirectoryReader _directoryReader;
    SpaceRemover _spaceRemover;
    PathProcessor _pathProcessor;

    [[nodiscard]] size_t processFile(const std::string& filePath) const;

public:
    /**
     * @brief Constructor
     */
    explicit WhiteSpaceRemover(std::string &path, bool recursive = false, std::regex regex = std::regex(".*"));
    ~WhiteSpaceRemover() = default;

    size_t run();

    [[nodiscard]] PathType getPathType(const std::string &path) const override;

    [[nodiscard]] bool isFile(const std::string &path) const override;

    [[nodiscard]] bool isDirectory(const std::string &path) const override;

    int removeSpaces(std::string &line) const override;

    [[nodiscard]] std::vector<std::string>
    getFilesFromDirectory(const std::string &path, bool recursive, const std::regex &regex) const override;
};

#endif //WHITESPACEREMOVER_WHITESPACEREMOVER_HPP
