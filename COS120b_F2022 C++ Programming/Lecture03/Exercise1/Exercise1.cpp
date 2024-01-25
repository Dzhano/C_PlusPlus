#include <iostream>

int main()
{
    double hoursWorked, hourlyRate, salary;
    std::cout << "Enter the number of hours worked: ";
    std::cin >> hoursWorked;
    std::cout << "Enter the number of hourly rate: ";
    std::cin >> hourlyRate;

    if (hoursWorked > 40)
    {
        salary = (40 * hourlyRate) + (hoursWorked - 40)
            * hourlyRate * 1.5;
    }
    else { salary = hoursWorked * hourlyRate; }

    std::cout << "Salary: " << salary;

    return 0;
}