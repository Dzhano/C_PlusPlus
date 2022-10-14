#include <iostream>

float oddSum(int[], int);

int main()
{
    const int size = 9;
    int array[size] = { -85, -5, 1, 2, 6, 8, 56, 85, 100 };

    std::cout << "The sum of the odd numbers is: " << oddSum(array, size);
}

float oddSum(int array[], int size)
{
    float odds = 0;
    for (int i = 0; i < size; i++)
        if (array[i] % 2 != 0) odds += array[i];
    return odds;
}