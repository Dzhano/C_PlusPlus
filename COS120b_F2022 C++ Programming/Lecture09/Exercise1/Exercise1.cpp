#include <iostream>

int multiply(int, int);

int main()
{
    std::cout << multiply(5, 6);
}

int multiply(int a, int b)
{
    if (b == 1) return a;
    else return a + multiply(a, b - 1);
}