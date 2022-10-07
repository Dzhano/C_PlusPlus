#include <iostream>

std::string foo(std::string, std::string);

std::string foo(std::string a, std::string b)
{
    return a.length() >= b.length() ? a : b;
}