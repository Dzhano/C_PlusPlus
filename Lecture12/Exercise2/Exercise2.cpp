#include <iostream>
#include "Circle.h"
#include "Circle.cpp"

int main()
{
    double radius;
    std::cout << "Please enter a radius: ";
    std::cin >> radius;

    Circle circle;
    circle.setRadius(radius);


    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;
    std::cout << "Perimeter: " << circle.getPerimeter() << std::endl;
}