#pragma once

const double PI = 3.14;

class Circle {
private:
    double radius;
public:
    Circle();

    void setRadius(double);
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
};