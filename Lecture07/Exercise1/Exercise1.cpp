#include <iostream>

int main()
{
    int array[] = { -85, -5, 1, 2, 6, 8, 56, 85, 100 };
    int size = 9;
    float average = 0;
    for (int i = 0; i < size; i++) average += array[i];
    average /= size;
    std::cout << "The average is: " << average;
}