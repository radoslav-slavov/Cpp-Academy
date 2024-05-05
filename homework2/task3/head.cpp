#include <iostream>
#include <fstream>
#include <string>

void printHead(const std::string& filename, int numLines) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int count = 0;
    while (count < numLines && std::getline(file, line)) {
        std::cout << line << std::endl;
        count++;
    }

    file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename> <num_lines>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int numLines = std::stoi(argv[2]);

    printHead(filename, numLines);

    return 0;
}
