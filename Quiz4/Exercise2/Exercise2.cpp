#include <iostream>

int foo(std::string);

int main()
{
    std::string text = "This Is Test";
    std::cout << foo(text);
}

int foo(std::string input)
{
    int count = 0;

    for (int i = 0; i < input.size(); i++)
        if (islower(input[i])) count++;

    return count;
}