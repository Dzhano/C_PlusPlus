#include <iostream>

void fillArray(int* a, int size);

int main()
{
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    int* array = new int[size];

    fillArray(array, size);
}

void fillArray(int* a, int size) {
    // First way
    for (int i = 0; i < size; i++)
        *(a + i) = i + 1;

    /* Second way
    int i = 0;
    while (i < size)
    {
        *(a + i) = i + 1;
        i++;
    }*/
}