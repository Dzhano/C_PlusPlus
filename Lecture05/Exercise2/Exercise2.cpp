#include <iostream>

float perimeter(float, float);
float area(float, float);

int main()
{
    float a, b;
    std::cout << "Enter two rectangle dimensions: ";
    std::cin >> a >> b;

    std::cout << "The perimeter of the triangle is " << perimeter(a, b) << std::endl;
    std::cout << "The area of the triangle is " << area(a, b);
}

float perimeter(float a, float b)
{
    return 2 * a + 2 * b;
}

float area(float a, float b)
{
    return a * b;
}