#include <iostream>

int main()
{
    float price, tax;
    std::cout << "Enter the price of the product: ";
    std::cin >> price;

    if (price >= 0 && price <= 19.99) tax = 0;
    else if (price >= 20 && price <= 99.99) tax = 0.06;
    else if (price >= 100) tax = 0.08;

    std::cout << "The total price of the product with the applicable tax is: " << price + (price * tax);
}
