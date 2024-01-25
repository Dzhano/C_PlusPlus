#include <iostream>

int main()
{
    float cents, nickels;

    std::cout << "Enter the number of pennies you have:\n";
    std::cin >> cents;

    std::cout << "\n";

    std::cout << "Enter the number of nickels you have:\n";
    std::cin >> nickels;

    cents += 5 * nickels;

    std::cout << cents / 100 << "$";
}
