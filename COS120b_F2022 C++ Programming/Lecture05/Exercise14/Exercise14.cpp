#include <iostream>

std::string getInitials(std::string, std::string);

int main()
{
    std::string firstName, lastName;
    std::cout << "Enter a full name: ";
    std::cin >> firstName >> lastName;

    std::cout << "Its initials are " << getInitials(firstName, lastName);
}

std::string getInitials(std::string firstName, std::string lastName)
{
    return firstName + " " + lastName;
}