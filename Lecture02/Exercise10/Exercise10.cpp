#include <iostream>

int main()
{
    float cents, nickels, dime, quarters;

    std::cout << "Enter the number of pennies you have:\n";
    std::cin >> cents;

    std::cout << "\n";

    std::cout << "Enter the number of nickels you have:\n";
    std::cin >> nickels;

    std::cout << "\n";


    std::cout << "Enter the number of dimes you have:\n";
    std::cin >> dime;

    std::cout << "\n";


    std::cout << "Enter the number of quarters you have:\n";
    std::cin >> quarters;

    std::cout << "\n";


    cents += (5 * nickels) + (10 * dime) + (25 * quarters);
    std::cout << cents / 100 << "$";
}
