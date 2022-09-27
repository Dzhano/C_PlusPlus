#include <iostream>
#include <cmath>

double hypotenuseLength(double, double);

int main()
{
    double a, b;
    std::cout << "Enter the two sides of triangle: ";
    std::cin >> a >> b;

    std::cout << "The length of the hypotenuse is " << hypotenuseLength(a, b);
}

double hypotenuseLength(double a, double b)
{
    return sqrt(a * a + b * b);
}