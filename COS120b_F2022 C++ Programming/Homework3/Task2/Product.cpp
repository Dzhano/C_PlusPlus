// The implementation file (cpp) with the implementation of the class

#include <iostream>  // Allowing us to use std::cout
#include "Product.h" // Connecting the header file

// Constructors
Product::Product() { // Empty which will declare the private values by default (empty or 0).
	name = ""; // We can use setName(""), but there is no point, because will definately be no mistakes in this operation with this value.
	unitPrice = 0; // We can use setUnitPrice(0), but there is no point, because 0 is allowed even though that means the product is free.
	quantity = 0; // We can use setQuantity(0), but there is no point, because 0 is allowed which means there is no more from the product.
}

Product::Product(std::string name, double unitPrice, int quantity) { // with three variables - one for each private value.
	setName(name); // Using the constructor to set the name of the product.
	setUnitPrice(unitPrice); // Using the constructor to set the price per unit of the product.
	setQuantity(quantity); // Using the constructor to set the quantity of the product.
}


void Product::setName(std::string name) { // Giving the variable "name" a value.
	this->name = name; // The name in this case can be whatever is written. Even if it is nothing ("").
}

std::string Product::getName() const { // Getting the value of the name variable.
	return name;
}


void Product::setUnitPrice(double price) { // Giving the variable "unitPrice" a value.
	unitPrice = price >= 0 ? price : 0; // The input price per unit cannot be less than zero, so it will be declared as 0.
}

double Product::getUnitPrice() const { // Getting the value of the unitPrice variable.
	return unitPrice;
}


void Product::setQuantity(int quantity) { // Giving the variable "quantity" a value.
	this->quantity = quantity >= 0 ? quantity : 0; // The input quantity cannot be less than zero, so it will be declared as 0.
}

int Product::getQuantity() const { // Getting the value of the quantity variable.
	return quantity;
}


double Product::getTotalPrice() const { // Getting the total price of the product by multiplying the unit price by the quantity.
	return getUnitPrice() * getQuantity();
}


void Product::display() { // Displaying the information about the product.
	std::cout << getName() << " " << getQuantity() << " x "
		<< getUnitPrice() << ", so the price is: " << getTotalPrice() << "." << std::endl;
}