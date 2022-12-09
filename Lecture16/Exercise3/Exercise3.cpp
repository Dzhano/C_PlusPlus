#include <iostream>
#include <fstream>
#include <string>
#include "College.cpp"

using namespace std;

int main()
{
	ifstream input("");
	if (input.fail()) {
		cout << "Wrong file";
		return -1;
	}


	string name;
	int numStudents, numFaculty;

	// American University#12 12
	getline(input, name, '#');
	while (!input.eof()) {
		input >> numStudents >> numFaculty;
		input.ignore(1, '\n');
		getline(input, name, '#');

		College(name, numStudents, numFaculty);
	}

	input.close();
}