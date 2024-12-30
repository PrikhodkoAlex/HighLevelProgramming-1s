// YTC/b-24-1-o
//Prikhodko Alexandr
//lab 1
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>

void task11_1();
void task12_1();
void task11_2();
void task12_2();


int main() {
    std::string numberOfTask;
    std::cout << "Enter number of task (11.1 / 11.2 / 12.1 / 12.2) << "; std::getline(std::cin, numberOfTask);
    if (numberOfTask == "11.1") task11_1();
    else if (numberOfTask == "11.2") task11_2();
    else if (numberOfTask == "12.1") task12_1();
    else if (numberOfTask == "12.2") task12_2();
    std::cin >> numberOfTask;
    return 0;  
}

void task11_1()
{
    std::cout << "Tast 11.1" << std::endl;
    std::string filmName;
    unsigned short int timeH, timeM, row, column;
    unsigned int ticketPrice;
    std::cout << "Enter film Name << "; std::getline(std::cin, filmName);
    std::cout << "Enter time of begin(hh mm) << "; std::cin >> timeH >> timeM;
    std::cout << "Enter row of seat << "; std::cin >> row;
    std::cout << "Enter number of seat << "; std::cin >> column;
    std::cout << "Enter ticket price << "; std::cin >> ticketPrice;
    std::cout << "\nThe film name is \"" << filmName << "\". Film starts in " << timeH << ':' << timeM << ".\n";
    std::cout << "Your seat locates in " << row << " row " << column << " number.\n";
    std::cout << "The ticket price is " << ticketPrice << ".\n\n\n";
}


void task12_1() {

    std::cout << "Tast 12.1" << std::endl;
    std::string cameraModel;
    unsigned short int screenSize, memorySize, cameraWeight;
    unsigned int cameraPrice;

    std::cout << "Enter camera model << "; std::getline(std::cin, cameraModel);
    std::cout << "Enter camera price << "; std::cin >> cameraPrice;
    std::cout << "Enter size of screen (megapixels) << "; std::cin >> screenSize;
    std::cout << "Enter size of memory << "; std::cin >> memorySize;
    std::cout << "Enter camera weight << "; std::cin >> cameraWeight;
    std::cout << "The camera model " << cameraModel << " has screen size " << screenSize;
    std::cout << " megapixels and memory size " << memorySize << ".\n";
    std::cout << "It cost " << cameraPrice << ". Camera weight is " << cameraWeight << ".\n";
}


void task12_2() {
    float r, z;
    std::cout << "Enter z << "; std::cin >> z;
    std::cout << "Enter r << "; std::cin >> r;
    float t = sqrt(log(fabs(M_PI * r)) / (1000 + (r * z)));
    float m = 180 * atan((exp(5 * t) - exp(0 - (5 * t))) / (exp(z * t) - exp(0 - (z * t))));
    std::cout << "          ln(|pi*r|)\n";
    std::cout << "t = sqrt(------------) = " << t << std::endl;
    std::cout << "          1000 + rz\n";
    std::cout << "                 e^(5t) - e^(-5t)\n";
    std::cout << "m = 180 * arctg(------------------) = " << m << std::endl;
    std::cout << "                 e^(zt) - e^(-zt)\n";
    std::cout << 180 * atan(0.143631) << std::endl;
}


void task11_2() {
    float x, k;
    std::cout << "Enter x << "; std::cin >> x;
    std::cout << "Enter k << "; std::cin >> k;
    float n = log(M_PI / (k * x - 1600));
    float b = sqrt(((sin(n) * sin(n)) + sin(n * n)) / (fabs(sin(n)) + exp(0 - x)));
    std::cout << "          pi\n";
    std::cout << "n = ln(---------) = " << n << std::endl;
    std::cout << "       kx - 1600\n";
    std::cout << "         (sin(n))^2 + sin(n^2)\n";
    std::cout << "b = sqrt(---------------------) = " << b << std::endl;
    std::cout << "           |sin(n)| + e^(-x)\n";
}