#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the file
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise1\\name.txt");

    //Check whether the file was opened successfully
    if (input.fail()) {
        std::cout << "Cannot open the file." << std::endl;
        return -1;
    }

    int count = 0;
    char c;

    // Process the file
    while (input.get(c)) count++;

    // Close the file
    input.close();

    // Result
    std::cout << "The number of characters (letters, spaces, everything) in a text file is " << count;
}