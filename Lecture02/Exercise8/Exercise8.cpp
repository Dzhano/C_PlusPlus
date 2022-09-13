#include <iostream>

int main()
{
    float pounds, kilograms;

    std::cout << "Enter the weight of the apples in pounds:\n";
    std::cin >> pounds;
    kilograms = pounds * 0.45359237;

    std::cout << "\n";

    std::cout << "The price of the apples, considering they are 1.2/kg, is: " << kilograms * 1.2;

    return 0;
}
