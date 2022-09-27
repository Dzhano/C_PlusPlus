#include <iostream>

float payrise(float);

int main()
{
    float salary;
    std::cout << "Enter the salary: ";
    std::cin >> salary;

    std::cout << "The estimated salary for next year is " << payrise(salary);
}

float payrise(float salary)
{
    if (salary < 40000) return salary * 1.05;
    else return salary * 1.02 + 2000;
}