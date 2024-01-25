#include <iostream>
#include "Counter.h"

int main()
{
    int c;
    std::cout << "";
    std::cin >> c;

    Counter c1(c);
    std::cout << c1.getCount() << std::endl;
    std::cout << c1.getMaxValue() << std::endl;

    c1.setCount(1);
    c1.setMaxValue(c);
    c1.increment();
    c1.decrement();
}