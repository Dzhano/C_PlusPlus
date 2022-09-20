#include <iostream>

int main()
{
    std::cout << "Enter a number between 1 and 10: ";
	int n;
	while (true)
	{
		std::cin >> n;
		if (n > 0 && n < 11) break;
		std::cout << "Try another number: ";
	}

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}