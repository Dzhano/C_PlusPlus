#include <string>
#include <iostream>
using namespace std;

class Fruit {
private:
	string color, taste;
public:
	Fruit(string color, string taste) {
		setColor(color);
		setTaste(taste);
	}

	void setColor(string color) { this->color = color; }
	string getColor() { return color; }

	void setTaste(string taste) { this->taste = taste; }
	string getTaste() { return taste; }


	virtual void display() {
		cout << "Color: " << getColor() << endl << "Taste: " << getTaste() << endl;
	}
};

class Apple : public Fruit {
	Apple(string color, string taste) : Fruit(color, taste) {}

	void display() {
		cout << "Type of the fruit: apple" << endl;
		Fruit::display();
	}
};

class Grapefruit : public Fruit {
	Grapefruit(string color, string taste) : Fruit(color, taste) {}

	void display() {
		cout << "Type of the fruit: grapefruit" << endl;
		Fruit::display();
	}
};