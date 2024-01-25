#include <iostream>

int main()
{
	int num1 = 0, num2 = 1, i = 1;
	std::cout << 0 << " 1 ";

	do
	{
		std::cout << i << " ";
		num1 = num2;
		num2 = i;
		i = num1 + num2;
	} while (i < 101);
}