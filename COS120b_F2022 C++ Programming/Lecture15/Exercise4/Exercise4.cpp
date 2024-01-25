#include <iostream>
#include "Location.h"

int main()
{
    Location location1(4, 6);
    Location location2(7, 5);

    Location location3 = location1 + location2;

    std::cout << "The statement that location1 is the same as location2 is " << (location1 == location2) << "." << std::endl;
    std::cout << location1 << std::endl;
    std::cout << location2 << std::endl;
    std::cout << location3 << std::endl;
}