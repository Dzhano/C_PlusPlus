#include <iostream>

enum product { bread, milk, meat, vegetables };

int main()
{
    char input;
    product myproduct;
    bool done = false;
    do
    {
        std::cout << "Please enter b (for bread), m (milk), t (for meat) or v (for vegetables)" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 'b':
            myproduct = bread;
            done = true;
            break;
        case 'm':
            myproduct = milk;
            done = true;
            break;
        case 't':
            myproduct = meat;
            done = true;
            break;
        case 'v':
            myproduct = vegetables;
            done = true;
            break;
        }
    } while (!done);

    std::cout << "You have entered: " << myproduct;
}