#include <iostream>

unsigned  long fibonacci(int n) {
    if (n <= 1) return n;

    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long c;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    std::cout << "Enter position: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Only positive ints are accepted" << std::endl;
        return 1;
    }

    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;

    return 0;
}
