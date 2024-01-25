#include <iostream>

void printPartial(int a[], int start, int end, int size);

int main()
{
    int numbers[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, };
    printPartial(numbers, 7, 40, 12);
}

void printPartial(int a[], int start, int end, int size)
{
    if (start > end)
    {
        start = 0;
        end = size - 1;
    }
    if (start < 0) start = 0;
    if (size < end) end = size - 1;

    for (int i = start; i <= end; i++)
        std::cout << a[i];
}