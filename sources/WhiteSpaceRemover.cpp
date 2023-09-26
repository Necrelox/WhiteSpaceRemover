//
// Created by ruby on 25/09/2023.
//

#include <string>
#include <regex>
#include <utility>
#include <fstream>
#include <iostream>
#include "WhiteSpaceRemover.hpp"

WhiteSpaceRemover::WhiteSpaceRemover(std::string &path, bool recursive, std::regex regex)
: _path(path), _regex(std::move(regex)), _recursive(recursive)
{

}

IPathProcessor::PathType WhiteSpaceRemover::getPathType(const std::string &path) const {
    return _pathProcessor.getPathType(path);
}

bool WhiteSpaceRemover::isFile(const std::string &path) const {
    return _pathProcessor.isFile(path);
}

bool WhiteSpaceRemover::isDirectory(const std::string &path) const {
    return _pathProcessor.isDirectory(path);
}

int WhiteSpaceRemover::removeSpaces(std::string &line) const {
    return _spaceRemover.removeSpaces(line);
}

std::vector<std::string>
WhiteSpaceRemover::getFilesFromDirectory(const std::string &path, bool recursive, const std::regex &regex) const {
    return _directoryReader.getFilesFromDirectory(path, recursive, regex);
}

size_t WhiteSpaceRemover::run() {
    PathType pathType = getPathType(_path);
    if (pathType == PathType::NOT_EXISTING)
        throw std::runtime_error("Path does not exist");

    size_t numberSpacesRemoved = 0;
    if (this->isFile(this->_path)) {
        numberSpacesRemoved += processFile(this->_path);
    } else {
        std::vector<std::string> files = this->getFilesFromDirectory(this->_path, this->_recursive, this->_regex);
        for (const auto &filePath : files)
            numberSpacesRemoved += processFile(filePath);
    }
    return numberSpacesRemoved;
}

size_t WhiteSpaceRemover::processFile(const std::string& filePath) const {
    std::ifstream fileStream(filePath);
    if (!fileStream.is_open())
        throw std::runtime_error("Unable to open file: " + filePath);

    fileStream.seekg(0, std::ios::end);
    size_t estimatedLines = fileStream.tellg() / 50;
    fileStream.seekg(0, std::ios::beg);
    std::vector<std::string> lines;
    lines.reserve(estimatedLines);

    size_t numberSpacesRemoved = 0;
    std::string line;
    while (std::getline(fileStream, line)) {
        numberSpacesRemoved += this->removeSpaces(line);
        lines.push_back(line);
    }

    std::ofstream outFileStream(filePath, std::ios::trunc);
    if (!outFileStream.is_open())
        throw std::runtime_error("Unable to open file: " + filePath);

    for (const std::string& processedLine : lines)
        outFileStream << processedLine << '\n';

    outFileStream.close();
    fileStream.close();
    return numberSpacesRemoved;
}
