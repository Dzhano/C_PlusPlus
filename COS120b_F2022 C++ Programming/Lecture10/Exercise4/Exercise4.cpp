#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the files
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise4\\original.txt");
    std::ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise4\\copy.txt");

    //Check whether the files were opened successfully
    if (input.fail()) {
        std::cout << "Cannot open the original file." << std::endl;
        return -1;
    }
    if (output.fail()) {
        std::cout << "Cannot open the copy file." << std::endl;
        return -1;
    }

    // Process the files
    char c;
    while (input.get(c)) output.put(c);

    // Close the files
    input.close();
    output.close();
}