#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

FileReader::FileReader(const std::string& filename) : filename(filename) {}

std::string FileReader::getFileContent() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}