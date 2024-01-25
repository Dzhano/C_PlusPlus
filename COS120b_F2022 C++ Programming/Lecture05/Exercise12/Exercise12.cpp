#include <iostream>

void display(char, int);

int main()
{
    char ch; int num;
    std::cout << "Please enter a character: ";
    std::cin >> ch;
    std::cout << "Please enter a number: ";
    std::cin >> num;

    display(ch, num);
}

void display(char ch, int num)
{
    for (int i = 0; i < num; i++)
        std::cout << ch;
}