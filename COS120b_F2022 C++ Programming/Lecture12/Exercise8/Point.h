#pragma once
#include <cmath>

class Point {
private:
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	double calcDistance(const Point& b) {
		return pow((pow(b.x - x, 2) + pow(b.y - y, 2)), 0.5);
	}
};