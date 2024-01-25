#include <iostream>
#include "LongString.h"

int main()
{
    LongString longString("");

    std::cout << "Get char at position 4: " << longString.get(4) << std::endl;
    std::cout << "Length: " << longString.length << std::endl;
    longString.addString();
}