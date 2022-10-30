#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the file
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Homework2\\Task1\\products.txt"); // Since the task is going to be tested on another computer, but mine, the program address is going to be different than the one on my laptop.

    //Check whether the file was opened successfully
    if (input.fail()) {
        std::cout << "Failed to open the file!" << std::endl;
        return -1; // If the file is not open successfully, the program gets terminated immediatelly.
    }

    // Process the file
    float price; int quantity;
    float minTotalPrice = 0; float maxTotalPrice = 0;
    int count = 1;

    while (!input.eof()) // Checking whether there are any lines in the file and, if there are, the loop will go through all of them.
    {
        input >> price >> quantity;
        float totalPrice = price * quantity;
        if (count == 1)
        {
            minTotalPrice = totalPrice;
            maxTotalPrice = totalPrice;
            count++;
        }
        else
        {
            if (totalPrice < minTotalPrice) minTotalPrice = totalPrice;
            if (totalPrice > maxTotalPrice) maxTotalPrice = totalPrice;
        }
    }

    // Close the file
    input.close();

    // The output where we present the lowest and highest total prices.
    std::cout << "Max total price is: " << maxTotalPrice << std::endl;
    std::cout << "Min total price is: " << minTotalPrice;
}