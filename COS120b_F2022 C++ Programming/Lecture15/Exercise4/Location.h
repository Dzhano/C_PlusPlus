#pragma once
#include <ostream>
#include <string>

using namespace std;

template <class X, class Y>
class Location {
private:
	X x;
	Y y;
public:
	Location(X x, Y y) {
		this->x = x;
		this->y = y;
	}

	const Location& operator=(const Location& rhs) {
		if (this != &rhs) {
			x = rhs.x;
			y = rhs.y;
		}
		return *this;
	}

	bool operator==(const Location& rhs) const {
		return x == rhs.x && y == rhs.y ? true : false;
	}

	Location operator+(const Location& rhs) const {
		return Location(x + rhs.x, y + rhs.y);
	}

	friend ostream& operator<<(ostream& out, const Location& rhs) {
		out << "Location(" << rhs.x << ", " << rhs.y << ")";
		return out;
	}

	friend istream& operator>>(istream& in, Location& rhs) {
		in >> rhs.x >> rhs.y;
		return in;
	}
};