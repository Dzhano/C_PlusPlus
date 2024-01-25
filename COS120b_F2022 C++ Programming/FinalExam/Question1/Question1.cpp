#include <iostream>

template <class T>
T foo(T array[], const int size) {
	T maximum = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > maximum) {
			maximum = array[i];
		}
	}
	return maximum;
}

int main()
{
	int arr[4] = { 1, 4, 7, 2 };
	std::string arr2[3] = { "Ben", "Josh", "Dzhano" };
	std::cout << foo(arr, 4);
	std::cout << foo(arr2, 3);
}