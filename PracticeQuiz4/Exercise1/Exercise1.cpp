#include <iostream>
#include <cstring>

void printReverse(char[]);

int main()
{

}

void printReverse(char input[])
{
    for (int i = strlen(input) - 1; i >= 0; i--)
        std::cout << input[i];
}