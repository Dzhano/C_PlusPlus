#include <iostream>

int main()
{
    float radius, perimeter, area;
    std::cout << "Enter the circle's radius: ";
    std::cin >> radius;

    perimeter = 2 * 3.14 * radius;
    area = 3.14 * radius * radius;

    std::cout << "The cicle's perimeter is equal to " << perimeter << std::endl;
    std::cout << "The cicle's area is equal to " << area << std::endl;
    return 0;
}