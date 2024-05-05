#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void printTail(const std::string& filename, int numLines) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (lines.size() > numLines) {
            lines.erase(lines.begin());
        }
    }

    int startIdx = (lines.size() > numLines) ? lines.size() - numLines : 0;
    for (int i = startIdx; i < lines.size(); ++i) {
        std::cout << lines[i] << std::endl;
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

    printTail(filename, numLines);

    return 0;
}
