#include <iostream>

int main()
{
    // 6a
    int num;
    std::cout << "Enter a number in the range [1, 20]: ";
    std::cin >> num;

    while (num < 1 || num > 21)
    {
        std::cout << "Please enter a valid number: ";
        std::cin >> num;
    }

    // 6b
    for (int i = 1; i < 10; i++)
        std::cout << i << " x " << num << " = " << i * num << std::endl;
}