#include <iostream>
#include <cmath>


double calculateVertical(double r, double h){
    
    std::cout << "Enter radius: "<< std::endl;
    std::cin >> r;

    std::cout << "Enter height (filled to): " << std::endl;
    std::cin >> h;

    double volume = M_PI * pow(r, 2) * h;

    return volume;
} 

double calculateHorizontal(double radius, double filledHeight) {
    double segmentHeight = radius - filledHeight;
    double segmentArea = pow(radius, 2) * acos(segmentHeight / radius) - segmentHeight * sqrt(pow(radius, 2) - pow(segmentHeight, 2));
    double filledVolume = segmentArea * 2 * M_PI * radius;
    
    return filledVolume;
}

int main(){
char position;

    std::cout << "Is the cylinder 'v'ertical or 'h'orizontal? ";
    std::cin >> position;
    if (position == 'v' || position == 'V'){
        double radius, height;
        float volume = calculateVertical(radius, height);
        std::cout << "Volume of the cylinder is: " << volume << "cubic m" <<std::endl;
    } 
    else if (position == 'h' || position == 'H'){
        double radius, filledHeight;
        float volume = calculateHorizontal(radius, filledHeight);
        std::cout << "Volume of the cylinder is: " << volume << "cubic m" << std::endl;
        } 
    else 
        std::cout << "Invalid input! Please enter 'v' or 'h'." << std::endl;
    

    return 0;
}