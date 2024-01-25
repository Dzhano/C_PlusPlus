#include <iostream>

int evenlyDivisible(int[][4], int);

int main()
{
    int numbers[5][4] =
    { { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 } };

    std::cout << "The count of numbers evenly divisible either by 3 or by 8 is " << evenlyDivisible(numbers, 5);
}

int evenlyDivisible(int numbers[][4], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
        for (int y = 0; y < 4; y++)
            if (numbers[i][y] % 3 == 0
                || numbers[i][y] % 8 == 0)
                count++;

    return count;
}