#include <iostream>

void change(int& a, int& b);

int main()
{
    int a = 10; int b = 5;

    change(a, b);
    std::cout << a << " " << b;
}

void change(int& a, int& b)
{
    int c = a;

    a = b;
    b = c;
}