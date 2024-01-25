#include <iostream>

int main()
{
    std::cout << "Enter number: ";
    int number;
    std::cin >> number;
    switch (number)
    {
    case 2:
        std::cout << "2";
        break;
    case 3:
        std::cout << "3";
        break;
    default:
        std::cout << "Something else";
        break;
    }
}