#include <iostream>

void change(int* a, int* b);

int main()
{
    int a = 10; int b = 5;
    int* p = &a; int* q = &b;

    change(p, q);
    std::cout << *p << " " << *q;
}

void change(int* a, int* b)
{
    int c = *a;

    *a = *b;
    *b = c;
}