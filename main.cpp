#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

std::vector<std::filesystem::path> get_files(const std::filesystem::path& path) {
    std::vector<std::filesystem::path> files;
    for (const std::filesystem::directory_entry &entry : std::filesystem::recursive_directory_iterator(path))
        if (entry.is_regular_file())
            files.push_back(entry.path());
    return files;
}

void rtrim(std::string& s, size_t &spaceRemoved) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    if (end != std::string::npos) {
        spaceRemoved += s.size() - end - 1;
        s.erase(end + 1);
    } else {
        spaceRemoved += s.size();
        s.clear();
    }
}

void trimWhiteSpaceFiles(const std::filesystem::path &path, size_t &spaceRemoved) {
    std::ifstream inFile(path);
    if (!inFile.is_open())
        throw std::runtime_error("Error while opening file : " + path.string());

    inFile.seekg(0, std::ios::end);
    size_t estimatedLines = inFile.tellg() / 50;
    inFile.seekg(0, std::ios::beg);
    std::vector<std::string> lines;
    lines.reserve(estimatedLines);

    std::string line;
    while (std::getline(inFile, line)) {
        rtrim(line, spaceRemoved);
        lines.push_back(line);
    }

    std::ofstream outFile(path, std::ios::trunc);
    if (!outFile.is_open())
        throw std::runtime_error("Error while opening file : " + path.string());

    for (const std::string& processedLine : lines)
        outFile << processedLine << '\n';
}

int main(int ac, char **av) {
    if (ac != 2)
        return -1;
    std::vector<std::filesystem::path> files = get_files(av[1]);

    std::cout << "Found " << files.size() << " files :" << std::endl;
    size_t totalSpaceRemoved = 0;
    for (const std::filesystem::path &file : files)
        try {
            size_t spaceRemoved = 0;
            trimWhiteSpaceFiles(file, spaceRemoved);
            std::cout << file << ": " << spaceRemoved << " spaces removed" << std::endl;
            totalSpaceRemoved += spaceRemoved;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    std::cout << "Total spaces removed : " << totalSpaceRemoved << std::endl;
    return 0;
}
