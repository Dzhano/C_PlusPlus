#include <iostream>

int main()
{
    std::cout << "Enter 3 numbers: ";
    float num1, num2, num3, minimum;
    std::cin >> num1 >> num2 >> num3;

    if (num1 < num2 && num1 < num3) minimum = num1;
    else if (num2 < num1 && num2 < num3) minimum = num2;
    else if (num3 < num2 && num3 < num1) minimum = num3;

    std::cout << minimum;
}