#include <iostream>

template <class T>
T lastest(T a, T b, T c) {
    T max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int main()
{
    
}