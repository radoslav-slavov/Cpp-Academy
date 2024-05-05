#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void countWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int numLines = 0;
    int numWords = 0;
    int numChars = 0;

    std::string line;
    while (std::getline(file, line)) {
        numLines++;
        numChars += line.size();

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            numWords++;
        }
    }

    file.close();

    std::cout << numLines << " " << numWords << " " << numChars << " " << filename << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    countWords(filename);

    return 0;
}
