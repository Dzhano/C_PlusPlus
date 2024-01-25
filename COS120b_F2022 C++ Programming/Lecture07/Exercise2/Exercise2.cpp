#include <iostream>

int positives(int[], int);

int main()
{
    const int size = 9;
    int array[size] = { -85, -5, 1, 2, 6, 8, 56, 85, 100 };

    std::cout << "The positive numbers are " << positives(array, size);
}

int positives(int array[], int size)
{
    float positive = 0;
    for (int i = 0; i < size; i++)
        if (array[i] > 0) positive++;
    return positive;
}