#include <iostream>

template <class T>
int returnTargetIndex(T array[], const int size, const T& target) {
	for (int i = 0; i < size; i++)
		if (array[i] == target) {
			return i;
		}
	return -1;
}

int main()
{
	int intTarget = 34;
	int numbers[5] = {23, 56, 34, -5, 100};
	std::cout << "Int target index: " << returnTargetIndex(numbers, 5, intTarget) << std::endl;

	std::string stringTarget = "Ivan";
	std::string names[4] = {"Dzhano", "George", "Fedi", "Alex"};
    std::cout << "String target index: " << returnTargetIndex(names, 4, stringTarget) << std::endl;
}