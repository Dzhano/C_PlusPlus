#include <iostream>

int main()
{
    std::string input;
    std::cout << "Please enter a string: ";
    std::cin >> input;

    for (int i = 0; i < 21; i++)
        std::cout << input << std::endl;
}