#include "Circle.h"
#include <math.h>

Circle::Circle() {
    radius = 0;
}

void Circle::setRadius(double set) {
    radius = set > 0 ? set : 1;
}
double Circle::getRadius() const {
    return radius;
}
double Circle::getArea() const {
    return radius * radius * PI;
}
double Circle::getPerimeter() const {
    return 2 * PI * radius;
}