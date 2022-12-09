#include <string>
#include <iostream>
using namespace std;

class Person {
private:
	string name, address;
public:
	Person(string name, string address) {
		this->name = name;
		this->address = address;
	}

	virtual void display() {
		cout << "Name: " << name << endl << "Address: " << address << endl;
	}
};

class Student : public Person {
private:
	string major;
public:
	Student(string name, string address, string major) : Person(name, address) {
		this->major = major;
	}

	void display() {
		Person::display();
		cout << "Major: " << major << endl;
	}
};

class Instructor : public Person {
private:
	double salary;
public:
	Instructor(string name, string address, double salary) : Person(name, address) {
		this->salary = salary;
	}

	void display() {
		Person::display();
		cout << "Salary: " << salary << endl;
	}
};