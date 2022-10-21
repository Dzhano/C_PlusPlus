#include <iostream>

int main()
{
    int numbers[5][4] =
    { { 7, 1, 9, 4 },
        { 6, 2, 9, 5 },
        { 5, 3, 9, 2 },
        { 4, 2, 9, 7 },
        { 3, 1, 9, 1 } };

    int sumOfNumbersInColumns[4];

    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int y = 0; y < 5; y++) sum += numbers[y][i];

        sumOfNumbersInColumns[i] = sum;
    }

    for (int i = 0; i < 4; i++)
        std::cout << sumOfNumbersInColumns[i] << " ";
}