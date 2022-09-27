#include <iostream>

bool isValidTriangle(double, double, double);
double calcPerimeter(double, double, double);
double calcArea(double, double, double);

int main()
{
    double a, b, c;
    std::cout << "Enter three parameters: ";
    std::cin >> a >> b >> c;

    if (isValidTriangle) std::cout << "The parameters can form a valid triangle." << std::endl;
    else std::cout << "The parameters cannot form a valid triangle." << std::endl;
    std::cout << "The parameter of the potential triangle is " << calcPerimeter(a, b, c) << std::endl;
    std::cout << "The area of the potential triangle is " << calcArea(a, b, c) << std::endl;
}

bool isValidTriangle(double a, double b, double c)
{
    if (a + b > c && a + c > b && c + b > a) return true;
    else return false;
}

double calcPerimeter(double a, double b, double c)
{
    if (isValidTriangle) return a + b + c;
    else return 0;
}

double calcArea(double a, double b, double c)
{
    // Heron’s formula: https://www.mathopenref.com/heronsformula.html

    if (isValidTriangle) return (a + b + c) / 2;
    else return 0;
}