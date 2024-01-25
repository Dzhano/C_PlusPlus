#include <iostream>

int main()
{
    float a, b, c;
    std::cout << "Enter the value of the three numbers: \n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b; 
    std::cout << "c = ";
    std::cin >> c;

    std::cout << "a * a + b * b = " << (a * a) + (b * b) << std::endl;
    std::cout << "b * b - 4 * a * c = " << b * b - 4 * a * c << std::endl;
    std::cout << "(1 + b * b + c * c) / 1 + a * a = " << (1 + b * b + c * c) / 1 + a * a;
}
