#include <iostream>

struct product
{
    std::string name;
    double price;
    int quantity;
};

double totalProductPrice(product[], int);

int main()
{
    product products[3] = { {"bread", 1.0, 1}, {"vegetables", 2.2, 4}, {"meat", 2.6, 3} };
    std::cout << "The total price of all products is " << totalProductPrice(products, 3);
}

double totalProductPrice(product products[], int size)
{
    double totalPrice = 0;

    for (int i = 0; i < size; i++)
        totalPrice += products[i].price * products[i].quantity;

    return totalPrice;
}