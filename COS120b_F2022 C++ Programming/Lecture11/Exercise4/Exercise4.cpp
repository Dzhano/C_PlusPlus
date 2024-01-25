#include <iostream>

void printArray(int* a, int size);

int main()
{
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    int* array = new int[size];

    printArray(array, size);
}

void printArray(int* a, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << "The address: " << a + i << std::endl;
        std::cout << "The value: " << *(a + i) << std::endl;
        std::cout << std::endl;
    }
}