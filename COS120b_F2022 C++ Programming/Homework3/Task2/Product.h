// The header file with the class declaration

#pragma once
#include <string> // so we can use std::string for the name

class Product {
private:
	std::string name; // The name of the product.
	double unitPrice; // The price per unit of the product. It should be a double or a float because the price can be decimal.
	int quantity; // The quantity of the product. It should be a int because the quantity is always a whole number.
public:
	// Constructors
	Product(); // Empty which will declare the private values by default (empty or 0).
	Product(std::string, double, int); // with three variables - one for each private value.


	void setName(std::string); // Giving the variable "name" a value.
	std::string getName() const; // Getting the value of the name variable.

	void setUnitPrice(double); // Giving the variable "unitPrice" a value.
	double getUnitPrice() const; // Getting the value of the unitPrice variable.

	void setQuantity(int); // Giving the variable "quantity" a value.
	int getQuantity() const; // Getting the value of the quantity variable.

	double getTotalPrice() const; // Getting the total price of the product.

	void display(); // Displaying the information about the product.
};