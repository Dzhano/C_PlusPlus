#include <iostream>

struct person
{
    std::string name;
    int age;
};

int main()
{
    person people[] = { { "Dzhano", 19 }, { "Dobromir", 23 }, { "Radi Cho", 17 } };

    int age = people[0].age;
    std::string name = people[0].name;

    for (int i = 1; i < 3; i++)
        if (age < people[i].age)
        {
            age = people[i].age;
            name = people[i].name;
        }

    std::cout << "The oldest person is " << name;
}