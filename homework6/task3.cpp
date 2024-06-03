#include <iostream>
#include <algorithm>
#include <string>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    std::string sorted_str1 = str1;
    std::string sorted_str2 = str2;
    std::sort(sorted_str1.begin(), sorted_str1.end());
    std::sort(sorted_str2.begin(), sorted_str2.end());
    
    return sorted_str1 == sorted_str2;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings ARE anagrams." << std::endl;
    } else {
        std::cout << "The strings are NOT anagrams." << std::endl;
    }

    return 0;
}
