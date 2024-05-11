#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("numbers.txt");
    if (!inputFile) {
        std::cerr << "Error!\n";
        return 1;
    }  

    int num1, num2;
    inputFile >> num1 >> num2;

    int result = num1 ^ num2;

    std::cout << "Result: " << result << std::endl;

    inputFile.close();
    return 0;
}