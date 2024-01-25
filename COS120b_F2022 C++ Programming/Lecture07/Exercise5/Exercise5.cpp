#include <iostream>

void printTable(const int[][10]);

int main()
{
    int multiplicationTable[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            multiplicationTable[i][j] = (i + 1) * (j + 1);
    }

    printTable(multiplicationTable);
}

void printTable(const int multiplicationTable[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            std::cout << i + 1 << " * " << j + 1 << " = " << multiplicationTable[i][j] << "   ";

        std::cout << std::endl;
        std::cout << std::endl;
    }
}