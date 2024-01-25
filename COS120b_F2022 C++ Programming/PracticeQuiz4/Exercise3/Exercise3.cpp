#include <iostream>

void printArray(int[], int);
void print2Array(int[][4], int);

int main()
{
    int numbers[5][4] =
    { { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 },
        { 7, 8, 9, 2 } };
    print2Array(numbers, 5);
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << a[i];
}

void print2Array(int a[][4], int size)
{
    for (int i = 0; i < size; i++)
    {
        printArray(a[i], 4);
        std::cout << std::endl;
    }
}