#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int majorityElement(const std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;
    
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
        
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }
    
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    return (count > nums.size() / 2) ? candidate : -1;
}

int main() {
    std::string input;
    std::cout << "Enter the array: ";
    std::getline(std::cin, input);
    std::vector<int> nums;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    int majority = majorityElement(nums);
    
    if (majority != -1) {
        std::cout << "The majority element is: " << majority << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }
    
    return 0;
}
