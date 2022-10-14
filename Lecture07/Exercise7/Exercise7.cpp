#include <iostream>

struct employee
{
    std::string name;
    int rate;
    int hours;
};

void maximumSalary(const employee[]);

int main()
{
    employee employees[5] = { {"Dzhano", 7, 9}, {"Ivan", 4, 4}, {"Fadi", 7, 6}, {"Slavcho", 12, 13}, {"Samuil", 1, 4} };
    maximumSalary(employees);
}

void maximumSalary(const employee employees[])
{
    std::cout << "The maximum salaries for all employees are: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "For " << employees[i].name << ": " << employees[i].hours * employees[i].rate;
        std::cout << std::endl;
    }
}