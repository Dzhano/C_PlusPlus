#include <iostream>

std::string getFirst(std::string);

int main()
{
    std::string firstName, lastName;
    std::cout << "Enter a full name: ";
    std::cin >> firstName >> lastName;

    std::cout << "The firstname is " << getFirst(firstName + " " + lastName);
}

std::string getFirst(std::string fullName)
{
    int index = fullName.find(" ");
    fullName.erase(index, fullName.length() - index);

    return fullName;
}