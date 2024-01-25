#include <iostream>
#include <cstring>

void uppercaseOnly(char[]);

int main()
{

}

void uppercaseOnly(char input[])
{
    for (int i = 0; i < strlen(input); i++)
        if (isupper(input[i])) std::cout << input[i];
}