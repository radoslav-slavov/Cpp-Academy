#include <iostream>
#include <fstream>

int main(){
    std::ifstream file("numbers.txt");

    double num1, num2, num3;
    file >> num1 >> num2 >> num3;
    file.close();

    double biggest = num1;
    if (num2 > biggest) 
        biggest = num2;
    
    if (num3 > biggest) 
        biggest = num3;
    

    std::cout << "The biggest number is: " << biggest << std::endl;
    return 0;
}