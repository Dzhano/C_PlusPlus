#include <iostream>

double operation(double, double, char);

int main()
{
    double a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    char op;
    std::cout << "Enter the operator: ";
    std::cin >> op;

    std::cout << "The result of the operation is " << operation(a, b, op);
}

double operation(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (a == 0 || b == 0) return 0;
        else return a / b;
    }
    return 0;
}