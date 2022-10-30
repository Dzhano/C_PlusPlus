#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the file
    std::ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise1\\name.txt");

    //Check whether the file was opened successfully
    if (output.fail()) {
        std::cout << "Cannot open the file." << std::endl;
        return -1;
    }

    // Process the file
    output << "Dzhano" << std::endl << "Mihaylov";

    // Close the file
    output.close();
}