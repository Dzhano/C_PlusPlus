#include <iostream>

float sumEvenRange(float, float);

int main()
{
	float start, end;
	std::cout << "Enter two numbers for range: ";
	std::cin >> start >> end;

	if (start < end)
		std::cout << "The sum of the numbers between the range " << start << " and " << end << " is " << sumEvenRange(start, end);
	else std::cout << "Error";
}

float sumEvenRange(float a, float b) 
{
	float sum = 0;
	for (int i = a; i <= b; i++)
		if (i % 2 == 0) sum += i;
	return sum;
}