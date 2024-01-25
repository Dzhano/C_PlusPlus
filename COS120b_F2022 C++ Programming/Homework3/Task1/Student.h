// The header file with the class declaration

#pragma once
#include <string> // so we can use std::string for the name

class Student {
private:
	std::string name;
	std::string major;
	int age;
public:
	// Constructors
	Student();
	Student(std::string, std::string, int);

	void setName(std::string); // Giving the variable "name" a value.
	std::string getName() const; // Getting the value of the name variable.

	void setMajor(std::string); // Giving the variable "major" a value.
	std::string getMajor() const; // Getting the value of the major variable.

	void setAge(int); // Giving the variable "age" a value.
	int getAge() const; // Getting the value of the age variable.

	void gettingOlder();

	void display(); // Displaying the information about the product.
};