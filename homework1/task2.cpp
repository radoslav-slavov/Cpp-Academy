#include <iostream>
#include <cmath>

float bmi_old(double weight, double height){
    
    return weight / pow(height, 2);
}

float bmi_new(double weight, double height){

    return weight * 1.3 / pow(height, 2.5);
}


int main(){
    double weight, height;

    std::cout << "Enter weight (kg): " << std::endl;
    std::cin >> weight;

    std::cout << "Enter height (m): " << std::endl;
    std::cin >> height;

    std::cout << "BMI (OLD formula) is "<< bmi_old(weight, height) << std::endl;
    std::cout << "BMI (NEW formula) is "<< bmi_new(weight, height) << std::endl;

    return 0;
}