#include <iostream>

int main()
{
    int a, b, c;
    std::cout << "Enter three integers: ";
    std::cin >> a >> b >> c;
    std::cout << "Their average is " << calcAverage(a, b, c);
}

float calcAverage(int a, int b, int c)
{
    float average = a + b + c;
    average /= 3;
    return average;
}