#include <iostream>

std::string getLast(std::string);

int main()
{
    std::string firstName, lastName;
    std::cout << "Enter a full name: ";
    std::cin >> firstName >> lastName;

    std::cout << "The lastname is " << getLast(firstName + " " + lastName);
}

std::string getLast(std::string fullName)
{
    std::string lastName;
    int index = fullName.find(" ");
    index++;
    lastName.assign(fullName, index);
    return lastName;
}
