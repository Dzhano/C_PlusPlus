#include <iostream>

int main()
{
	for (int i = 10; i <= 35; i+=5)
	{
		std::cout << "Temperature in Celsium: " << i << std::endl;
		std::cout << "Temperature in Fahrenheit: " << i * 1.8 + 32 << std::endl;
	}
}