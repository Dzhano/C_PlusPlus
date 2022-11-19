// The implementation file (cpp) with the implementation of the class

#include <iostream>  // Allowing us to use std::cout
#include "Student.h" // Connecting the header file

// Constructors
Student::Student() {
	name = "";
	major = "";
	age = 18;

}
Student::Student(std::string name, std::string major, int age) {
	setName(name);
	setMajor(major);
	setAge(age);
}

void Student::setName(std::string name) // Giving the variable "name" a value.
{
	this->name = name;
}

std::string Student::getName() const // Getting the value of the name variable.
{
	return name;
}

void Student::setMajor(std::string major) // Giving the variable "major" a value.
{
	this->major = major;
}

std::string Student::getMajor() const // Getting the value of the major variable.
{
	return major;
}


void Student::setAge(int age) // Giving the variable "age" a value.
{
	this->age = age >= 18 ? age : 18;
}

int Student::getAge() const // Getting the value of the age variable.
{
	return age;
}


void Student::gettingOlder()
{
	age += 1;
}

void Student::display() // Displaying the information about the product.
{
	std::cout << "Student: " << getName() << " with major " << getMajor() << " of age: " << getAge() << ".";
}