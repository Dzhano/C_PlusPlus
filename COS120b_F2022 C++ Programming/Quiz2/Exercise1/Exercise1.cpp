#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Please enter two numbers: ";
    std::cin >> num1 >> num2;
    if (num1 % 2 == 0 && num2 % 2 == 0)
        std::cout << "evens";
    else if (num1 % 2 != 0 && num2 % 2 != 0)
        std::cout << "odds";
}