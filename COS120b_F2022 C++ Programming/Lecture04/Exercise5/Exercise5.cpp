#include <iostream>

int main()
{
	std::cout << "Enter a number between 11 and 20: ";
	int n;
	while (true)
	{
		std::cin >> n;
		if (n > 10 && n < 21) break;
		std::cout << "Try another number: ";
	}

	if (n % 2 == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int y = 0; y < i; y++)
			{
				std::cout << '*';
			}
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = n; i > 0; i--)
		{
			for (int y = 0; y < i; y++)
			{
				std::cout << '*';
			}
			std::cout << std::endl;
		}
	}
	
}