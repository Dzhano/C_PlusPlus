#include <iostream>

int calcDivs(int); // Prototype

int main() // Invocation
{
    int numbers;
    std::cout << "Please enter how many numbers you would like to enter: ";
    std::cin >> numbers;

    for (int i = 0; i < numbers; i++)
    {
        int number;
        std::cout << "Please enter a number: ";
        std::cin >> number;

        int sum = calcDivs(number);
        std::cout << sum << std::endl;
    }

    std::cout << "All " << numbers << " numbers were processed.";
}

int calcDivs(int number) // Signature/Header
{
    if (number < 0) number += (0 - number) * 2;
    int sum = 0;
    for (int i = 1; i <= number; i++) if (number % i == 0) sum += i;
    return sum;
}