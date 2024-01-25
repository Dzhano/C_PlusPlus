#pragma once
#include <string>

class Triangle {
private:
    double sideA, sideB, sideC;
    bool isValid;
public:
    Triangle(double, double, double);

    std::string getType();
    double getPerimeter();
};