#include <iostream>

int main()
{
    std::string name;
    float age;
    std::cout << "Please enter your name and age.\n";

    std::cin >> name;
    std::cin >> age;

    std::cout << "Greetings " << name << "!" << std::endl << "Age: " << age;

    return 0;
}
