#include <iostream>

int main()
{
    std::cout << "Enter 4 integers:\n";
    int int1, int2, int3, int4;
    std::cin >> int1 >> int2 >> int3 >> int4;

    std::cout << "\n";

    std::cout << "Enter 2 floats:\n";
    float float1, float2;
    std::cin >> float1 >> float2;

    std::cout << ((int1 + int2) / float1) - (int3 / float2) + int4;
}