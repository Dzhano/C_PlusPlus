#include <iostream>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person() {
		name = "";
		age = 0;
	}

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	Person(const Person& other) {
		name = other.name;
		age = other.age;
	}

	~Person();
};