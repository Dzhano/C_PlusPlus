#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;

    isValid = (sideA + sideB > sideC) && (sideC + sideB > sideA) && (sideA + sideC > sideB);
}

std::string Triangle::getType() {
    if (isValid) {
        if (sideA == sideB && sideB == sideC) return "equilateral";
        else if (sideA == sideB || sideB == sideC || sideA == sideC)
            return "isosceles";
        else return "scalene";
    }
    else return "invalid";
}
double Triangle::getPerimeter() {
    return isValid ? sideA + sideB + sideC : 0;
}