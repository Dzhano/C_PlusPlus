#include <iostream>
#include <cmath>

float elipsePerimeter(float, float);

int main()
{
    float a, b;
    while (true)
    {
        std::cout << "Please enter the axes of the ellipse: ";
        std::cin >> a >> b;

        if (a >= 0 && b >= 0) break;
        else std::cout << "Invalid axes!" << std::endl;
    }

    std::cout << "The perimeter of the ellipse is: " << elipsePerimeter(a, b);
}

float elipsePerimeter(float a, float b)
{
    return 2 * 3.14 * sqrt((a * a + b * b) / 2);
}