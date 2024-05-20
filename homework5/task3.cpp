#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    if (n <= 3) {
        return true; // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Divisible by 2 or 3
    }
    for (int i = 5; i <= std::sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}
