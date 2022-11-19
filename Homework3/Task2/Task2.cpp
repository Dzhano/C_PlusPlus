// The test Diver class (cpp) with main function

#include <iostream> // Allowing us to use std::cout
#include <fstream> // Allowing us to use ifstream
#include "Product.h" // Connecting the header file

int main()
{
    // Open the file
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Homework3\\Task2\\products.txt"); // Since the task is going to be tested on another computer, but mine, the program address is going to be different than the one on my laptop.

    //Check whether the file was opened successfully
    if (input.fail()) {
        std::cout << "Failed to open the file!" << std::endl;
        return -1; // If the file is not open successfully, the program gets terminated immediatelly.
    }

    // Process the file
    std::string name; // The name of the current product.
    double unitPrice; // The price per unit of the current product. It should be a double or a float because the price can be decimal.
    int quantity; // The quantity of the current product. It should be a int because the quantity is always a whole number.

    double finalTotalPrice = 0; // The complete total price of all products combined together.

    while (!input.eof()) // Checking whether there are any lines in the file and, if there are, the loop will go through all of them.
    {
        input >> name >> unitPrice >> quantity; // From the current line we extract the needed information: the name, the unit price and the quantity.
        
        Product product(name, unitPrice, quantity); // Creating a new product
        product.display(); // Displays the information about the product

        finalTotalPrice += product.getTotalPrice(); // The total price of the current product gets added to the complete total price of all products.
    }

    // Close the file
    input.close();

    // The final output where we describe the complete total price which we have to pay for.
    std::cout << "The total amount we have to pay is "<< finalTotalPrice << ".";
}