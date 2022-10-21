#include <iostream>

int sumOfElements(int[], int);

int main()
{
    int numbers[5][4] =
    { { 7, 8, 9, 2 },
        { 6, 8, 9, 2 },
        { 5, 8, 9, 2 },
        { 4, 8, 9, 2 },
        { 3, 8, 9, 2 } };

    int sumOfNumbersInRows[5];

    for (int i = 0; i < 5; i++)
        sumOfNumbersInRows[i] = sumOfElements(numbers[i], 4);
    for (int i = 0; i < 5; i++)
        std::cout << sumOfNumbersInRows[i] << " ";
}

int sumOfElements(int numbers[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += numbers[i];

    return sum;
}