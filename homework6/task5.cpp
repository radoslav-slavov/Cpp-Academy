#include <iostream>
#include <vector>
#include <sstream>
#include <string>



void multiplyMatrices(const std::vector<std::vector<int>>& mat1,
                      const std::vector<std::vector<int>>& mat2,
                      std::vector<std::vector<int>>& result) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();
    
    if (cols1 != rows2) {
        std::cout << "Error: Matrix dimensions mismatch for multiplication!" << std::endl;
        return;
    }
    
    result.resize(rows1, std::vector<int>(cols2, 0));
    
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string input;
    int rows1, cols1, rows2, cols2;

    std::cout << "Enter the dimensions of the first matrix (rows columns): ";
    std::getline(std::cin, input);
    std::istringstream iss1(input);
    iss1 >> rows1 >> cols1;

    std::cout << "Enter the dimensions of the second matrix (rows columns): ";
    std::getline(std::cin, input);
    std::istringstream iss2(input);
    iss2 >> rows2 >> cols2;

    if (cols1 != rows2) {
        std::cout << "Error: Matrix dimensions mismatch for multiplication!" << std::endl;
        return 1;
    }

    std::cout << "Enter the elements of the first matrix:" << std::endl;
    std::vector<std::vector<int>> mat1(rows1, std::vector<int>(cols1));
    for (int i = 0; i < rows1; ++i) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        for (int j = 0; j < cols1; ++j) {
            iss >> mat1[i][j];
        }
    }

    std::cout << "Enter the elements of the second matrix:" << std::endl;
    std::vector<std::vector<int>> mat2(rows2, std::vector<int>(cols2));
    for (int i = 0; i < rows2; ++i) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        for (int j = 0; j < cols2; ++j) {
            iss >> mat2[i][j];
        }
    }

    std::vector<std::vector<int>> result;

    multiplyMatrices(mat1, mat2, result);

    std::cout << "Result of matrix multiplication:" << std::endl;
    printMatrix(result);

    return 0;
}

// Enter the dimensions of the first matrix (rows columns): 2 3
// Enter the dimensions of the second matrix (rows columns): 3 2
// Enter the elements of the first matrix:
// 1 2 3
// 4 5 6
// Enter the elements of the second matrix:
// 7 8
// 9 10
// 11 12
