#include <iostream>
#include "Triangle.h"

int main()
{
    Triangle triangles[4] = { {1, 2, 3}, {85, 85, 66}, {12, 90, 99}, {66, 66, 66 } };

    std::cout << "Triangle 1" << std::endl;
    std::cout << "Type: " << triangles[0].getType() << std::endl;
    std::cout << "Perimeter: " << triangles[0].getPerimeter() << std::endl;
    std::cout << std::endl;

    std::cout << "Triangle 2" << std::endl;
    std::cout << "Type: " << triangles[1].getType() << std::endl;
    std::cout << "Perimeter: " << triangles[1].getPerimeter() << std::endl;
    std::cout << std::endl;

    std::cout << "Triangle 3" << std::endl;
    std::cout << "Type: " << triangles[2].getType() << std::endl;
    std::cout << "Perimeter: " << triangles[2].getPerimeter() << std::endl;
    std::cout << std::endl;

    std::cout << "Triangle 4" << std::endl;
    std::cout << "Type: " << triangles[3].getType() << std::endl;
    std::cout << "Perimeter: " << triangles[3].getPerimeter() << std::endl;
}