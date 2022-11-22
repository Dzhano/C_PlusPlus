#include <iostream>
using namespace std;

template <class T>
T minimum(T array[], int size) {
    T min = array[0];

    for (int i = 0; i < size; i++)
        if (array[i] < min) min == array[i];

    return min;
}

int main()
{
    const int size = 8;
    int arrayChar[size] = {'a', 'f', 'G', '-', 'H', 'r', '0', 'e'};
    int arrayInt[size] = {1, 2, 4, 5, 6, 5, 0, 3};
    
    std::cout << "The int array's minimal value is " << minimum(arrayInt, size) << std::endl;
    std::cout << "The char array's minimal value is " << minimum(arrayChar, size) << std::endl;
}