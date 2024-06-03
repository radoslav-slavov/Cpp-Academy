#include <iostream>
#include <vector>
#include <sstream>

void merge(const std::vector<int>& arr1, const std::vector<int>& arr2, std::vector<int>& arr3) {
    int i = 0, j = 0;
    int k = 0;
    arr3.resize(arr1.size() + arr2.size());
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < arr1.size()) {
        arr3[k++] = arr1[i++];
    }
    while (j < arr2.size()) {
        arr3[k++] = arr2[j++];
    }
}

void print(const std::vector<int>& ans) {
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> parseInput(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        result.push_back(number);
    }
    return result;
}

int main() {
    std::string input1, input2;

    std::cout << "Enter the first sorted array: ";
    std::getline(std::cin, input1);
    std::vector<int> arr1 = parseInput(input1);

    std::cout << "Enter the second sorted array: ";
    std::getline(std::cin, input2);
    std::vector<int> arr2 = parseInput(input2);

    std::vector<int> arr3;
    merge(arr1, arr2, arr3);

    std::cout << "Array after merging: ";
    print(arr3);

    return 0;
}
