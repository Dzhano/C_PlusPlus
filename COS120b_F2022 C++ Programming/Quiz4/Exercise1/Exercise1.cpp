#include <iostream>

int foo(char[], int);

int main()
{
    char letters[5] = { 'a', 'A', '8', '.', 'b' };
    std::cout << foo(letters, 5);
}

int foo(char letters[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
        if (islower(letters[i])) count++;

    return count;
}