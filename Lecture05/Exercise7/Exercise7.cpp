#include <iostream>

void reversestring(std::string);

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    reversestring(input);
}

void reversestring(std::string input)
{
    for (int i = input.length() - 1; i >= 0; i--)
        std::cout << input[i];
}