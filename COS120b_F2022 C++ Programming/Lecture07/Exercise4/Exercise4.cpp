#include <iostream>

float average(const float[], int);

int main()
{
    float array[6] = { 46.8, 6, -8, 52, 100, -48 };
    std::cout << "The average of the array's indexes is " << average(array, 6);
}

float average(const float array[], int size)
{
    float average = 0;

    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }

    return average / size;
}