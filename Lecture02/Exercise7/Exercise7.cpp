#include <iostream>

int main()
{
    float price;
    std::cout << "Enter the price of the item:\n";
    std::cin >> price;

    std::cout << "The price with 25% discount: " << price * 0.75;

    return 0;
}
