#include <iostream>
using namespace std;

class Shape {
private:
	int x, y;
public:
	Shape(int x, int y) {
		setX(x);
		setY(y);
	}

	virtual void setX(int x) {
		this->x = x > 0 ? x : 1;
	}

	int getX() const {
		return x;
	}

	virtual void setY(int y) {
		this->y = y > 0 ? y : 1;
	}

	int getY() const {
		return y;
	}

	virtual int getArea() const = 0;
	virtual int getPerimeter() const = 0;

	virtual void display() {
		cout << "The type of the shape is: shape" << endl;
		cout << "X: " << getX() << endl << "Y: " << getY() << endl;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(int x, int y) : Shape(x, y) {}

	int getArea() const	{
		return getX() * getY();
	}

	int getPerimeter() const {
		return 2 * (getX() + getY());
	}

	virtual void display() {
		cout << "The type of the shape is: rectangle" << endl;
		cout << "X: " << getX() << endl << "Y: " << getY() << endl;
		cout << "Area: " << getArea() << endl << "Perimeter: " << getPerimeter() << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int x) : Rectangle(x, x) {}

	void setX(int x) {
		Rectangle::setX(x);
		Rectangle::setY(x);
	}
	
	void setY(int x) {
		Rectangle::setX(x);
		Rectangle::setY(x);
	}

	void display() {
		cout << "The type of the shape is: Square" << endl;
		cout << "X: " << getX() << endl << "Y: " << getY() << endl;
		cout << "Area: " << getArea() << endl << "Perimeter: " << getPerimeter() << endl;
	}
};