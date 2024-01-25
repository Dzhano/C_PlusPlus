#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the files
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise6\\input.txt");
    
    //Check whether the fils was opened successfully
    if (input.fail()) {
        std::cout << "Cannot open the file." << std::endl;
        return -1;
    }

    // Process the files
    std::string line;
    int count = 3;
    for (int i = 0; i < 3; i++) getline(input, line);

    while (getline(input, line) && count < 11) {
        count++;
        std::cout << line << std::endl;
    }

    // Close the files
    input.close();
}