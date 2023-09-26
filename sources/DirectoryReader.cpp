//
// Created by ruby on 26/09/2023.
//

#include <string>
#include <regex>
#include <filesystem>
#include "DirectoryReader.hpp"

std::vector<std::string> DirectoryReader::getFilesFromDirectory(
        const std::string &path,
        bool recursive,
        const std::regex& regex) const {
    std::vector<std::string> files;

    if (recursive) {
        for (const std::filesystem::directory_entry &entry : std::filesystem::recursive_directory_iterator(path))
            if (entry.is_regular_file() && std::regex_match(entry.path().string(), regex))
                files.push_back(entry.path().string());
    } else {
        for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(path))
            if (entry.is_regular_file() && std::regex_match(entry.path().string(), regex))
                files.push_back(entry.path().string());
    }

    return files;
}
