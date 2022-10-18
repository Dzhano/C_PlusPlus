#include <iostream>
#include <cstring>

void show_column(char str[]);

int main()
{

}

void show_column(char str[])
{
    for (int i = 0; i < strlen(str); i++)
        std::cout << str[i] << std::endl;
}