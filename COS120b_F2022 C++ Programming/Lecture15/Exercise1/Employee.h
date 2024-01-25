#pragma once
#include <ostream>
#include <string>

using namespace std;

class Employee {
private:
	std::string name;
	int age;
public:
	Employee(std::string name, int age) {
		this->name = name;
		this->age = age >= 1 ? age : 1;
	}


	bool operator<(const Employee& rhs) const {
		return age < rhs.age ? true : false;
	}
	
	bool operator>(const Employee& rhs) const {
		return age > rhs.age ? true : false;
	}


	friend ostream& operator<<(ostream& out, const Employee& value) {
		out << value.name;
		return out;
	}

	friend istream& operator>>(istream& in, Employee& value) {
		getline(in, value.name);
		in >> value.age;
		return in;
	}
};