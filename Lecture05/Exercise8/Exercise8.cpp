#include <iostream>

double sum(double, double, double, double);

int main()
{
    double a, b, c, d;
    std::cout << "Enter four numbers: ";
    std::cin >> a >> b >> c >> d;

    std::cout << "The sum of the numbers is " << sum(a, b, c, d);
}

double sum(double a, double b, double c, double d) 
{
    return a + b + c + d;
}