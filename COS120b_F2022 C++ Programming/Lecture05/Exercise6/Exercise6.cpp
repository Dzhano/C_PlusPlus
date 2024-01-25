#include <iostream>

int largest(int, int, int, int);

int main()
{
    int a, b, c, d;
    std::cout << "Enter four integers: ";
    std::cin >> a >> b >> c >> d;

    std::cout << "The largest number is " << largest(a, b, c, d);
}

int largest(int a, int b, int c, int d) 
{
    int largest = -999999;

    if (largest < a) largest = a;
    if (largest < b) largest = b;
    if (largest < c) largest = c;
    if (largest < d) largest = d;

    return largest;
}