#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the files
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise5\\original.txt");
    std::ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise5\\copy.txt");

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
    std::string line;
    int count = 0;

    while (getline(input, line)) {
        output << line;
        output << std::endl;
        count++;
    }

    output << std::endl;
    output << "Count: " << count;

    // Close the files
    input.close();
    output.close();
}