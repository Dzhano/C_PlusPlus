#include <iostream>
#include "Employee.h"

int main()
{
	Employee e1("John Smith", 30);
	Employee e2("Jane Doe", 25);

	if (e1 < e2) {
		cout << e1 << " is younger" << endl;
	}
	else {
		cout << e2 << " is younger" << endl;
	}
}