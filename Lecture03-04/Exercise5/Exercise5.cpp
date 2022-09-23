#include <iostream>

int main()
{
    int n;
    std::cout << "How many numbers would you like to enter?\n";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if (number % 2 == 0 && number % 3 == 0)
        {
            std::cout << "Divisible by both 2 and 3." << std::endl;
        }
        else if (number % 2 == 0)
        {
            std::cout << "Divisible by 2" << std::endl;
        }
        else if (number % 3 == 0)
        {
            std::cout << "Divisible by 3" << std::endl;
        }
    }
}