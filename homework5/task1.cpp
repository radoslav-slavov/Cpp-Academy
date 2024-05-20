#include <iostream>
#include <cmath> 

int main() {
    double radius;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    if (radius <= 0) {
        std::cout << "Enter a positive number" << std::endl;
        return 1;
    }

    double area = M_PI * radius * radius;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
