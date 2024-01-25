#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the file
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Homework2\\Task2\\transactions.txt"); // Since the task is going to be tested on another computer, but mine, the program address is going to be different than the one on my laptop.

    //Check whether the file was opened successfully
    if (input.fail()) {
        std::cout << "Failed to open the file!" << std::endl;
        return -1; // If the file is not open successfully, the program gets terminated immediatelly.
    }

    // Process the file
    int count = 0; // The number of transactions.
    float balance = 0; // The initial balance before the very first transaction.
    char transactionType; // The type of transaction which is going to be received (either 'd' or 'c').
    float money; // The amount of money which are going to be operated in the transaction.

    while (!input.eof()) // Checking whether there are any lines in the file and, if there are, the loop will go through all of them.
    {
        count++; // For every reached line there is one transaction. Therefore, their count is being increased by one with every iteration of the loop.
        input >> transactionType >> money; // From the current line we extract the transaction type and the amount of money.
        // Example for a line of transaction: <transaction type> <amount of money>

        switch (transactionType) // Checking what type is the transaction, so the right function can be executed.
        {
        case 'd': // d (debit – the amount should be subtracted from the balance)
            balance -= money;
            break;
        case 'c': // c (credit – the amount should be added to the balance).
            balance += money;
            break;
        }
    }

    // Close the file
    input.close();

    // The output where we describe the balance after all transactions and how many of them there were, no matter their types.
    std::cout << "Final Balance is " << balance << " after applying " << count << " transactions.";
}