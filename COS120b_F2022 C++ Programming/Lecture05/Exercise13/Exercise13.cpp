#include <iostream>

bool isDigit(std::string);

int main()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isDigit(input))
        std::cout << "The last character of the string is a digit.";
    else std::cout << "The last character of the string is not a digit.";
}

bool isDigit(std::string text)
{
    int lastIndex = text.length() - 1;
    char lastChar = text[lastIndex];
    switch (lastChar)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    default:
        return false;
    }
}