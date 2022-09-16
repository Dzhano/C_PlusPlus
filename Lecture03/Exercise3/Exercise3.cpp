#include <iostream>

int main()
{
    int year;
    std::cout << "Enter the year: ";
    std::cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        std::cout << "The year " << year << " is a leap year.";
    }
    else
    {
        std::cout << "The year " << year << " is not a leap year.";
    }
}