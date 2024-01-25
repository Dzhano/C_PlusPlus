#include <iostream>

int main()
{
    std::string name;
    int age;
    std::cout << "Enter name and age: ";
    std::cin >> name >> age;

    std::cout << "Hello " << name << " your age is " << age / 7 << " in dog years.";

    return 0;
}