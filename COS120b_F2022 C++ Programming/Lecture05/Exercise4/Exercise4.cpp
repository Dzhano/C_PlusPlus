#include <iostream>

int factorial(int);

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "The factorial og the number is " << factorial(number);
}

int factorial(int number)
{
    for (int i = number - 1; i > 1; i--)
        number *= i;
    return number;
}