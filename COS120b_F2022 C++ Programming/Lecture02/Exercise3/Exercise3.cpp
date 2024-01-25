#include <iostream>

int main()
{
    std::cout << "Write two whole numbers:\n";
    int number1, number2;
    std::cin >> number1 >> number2;

    std::cout << number1 << " + " << number2 << " = " << number1 + number2 << std::endl;
    std::cout << number1 << " - " << number2 << " = " << number1 - number2 << std::endl;
    std::cout << number1 << " * " << number2 << " = " << number1 * number2 << std::endl;
    std::cout << number1 << " / " << number2 << " = " << (float) number1 / number2 << std::endl;
}
