#include <iostream>
#include <climits>
#include <cmath>
#include <string>

std::string uppercase(std::string);

int main()
{
    std::string input;
    /* std::cout << "Enter a input: ";
    std::cin >> input; */
    input = "Hello World (2017)!";

    std::cout << uppercase(input);
}

std::string uppercase(std::string input)
{
    std::string result = "";
    for (int i = 0; i < input.length(); i++)
        if (isupper(input.at(i)))
            result += input.at(i);
    return result;
}