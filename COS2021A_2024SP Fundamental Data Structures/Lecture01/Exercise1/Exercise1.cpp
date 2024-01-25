#include <iostream>

using namespace std;

int main()
{
	int primes[] = { 2, 3, 5, 7, 11, 13 };

	cout << primes << endl; // location of primes[0] = 2
	cout << *primes << endl; // 2
	cout << primes + 4 << endl; // location of primes[4] = 11
	cout << *(primes + 4) << endl; // 11
	cout << primes[4] << endl; // 11
	cout << &primes[0] << endl; // location of primes[0] = 2
}