//
// Created by ruby on 26/09/2023.
//

#include <filesystem>
#include "PathProcessor.hpp"

PathProcessor::PathType PathProcessor::getPathType(const std::string &path) const {
    std::filesystem::path fsPath(path);
    if (std::filesystem::exists(fsPath) && fsPath.is_absolute())
        return PathType::ABSOLUTE;
    else if (std::filesystem::exists(fsPath) && fsPath.is_relative())
        return PathType::RELATIVE;
    else
        return PathType::NOT_EXISTING;
}

bool PathProcessor::isFile(const std::string &path) const {
    return std::filesystem::is_regular_file(std::filesystem::path(path));
}

bool PathProcessor::isDirectory(const std::string &path) const {
    return std::filesystem::is_directory(std::filesystem::path(path));
}




