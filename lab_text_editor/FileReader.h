#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

class FileReader {
public:
    FileReader(const std::string& filename);

    std::string getFileContent();

private:
    std::string filename;
};

#endif // FILEREADER_H