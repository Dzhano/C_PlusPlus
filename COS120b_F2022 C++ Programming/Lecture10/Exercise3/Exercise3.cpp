#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open the files
    std::ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise3\\numbers.txt");
    std::ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise3\\statistics.txt");

    //Check whether the files were opened successfully
    if (input.fail()) {
        std::cout << "Cannot open the number file." << std::endl;
        return -1;
    }
    if (output.fail()) {
        std::cout << "Cannot open the statistics file." << std::endl;
        return -1;
    }

    // Process the files
    int count = 0, sum = 0, number;

    while (input >> number)
    {
        count++;
        sum += number;
    }

    float average = (float) sum / count;

    output << "Count: " << count << std::endl << "Sum: " << sum << std::endl << "Average: " << average << std::endl;

    // Close the files
    input.close();
    output.close();
}