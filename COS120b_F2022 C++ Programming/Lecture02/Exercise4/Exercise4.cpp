#include <iostream>

int main()
{
    float pounds;

    std::cout << "Enter the weight in pounds:\n";
    std::cin >> pounds;

    std::cout << "\n";

    std::cout << "The weight in kilograms is: " << pounds * 0.45359237;

    return 0;
}

// This is literaly the same exercise from the previous lecture.