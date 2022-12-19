#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream input("...\\FinalExam_Demo\\numbers.txt");
	if (input.fail()) {
		cout << "Error..." << endl;
		return -1;
	}

	int number;
	vector<int> numbers;
	while (input >> number) numbers.push_back(number);

	input.close();

	sort(numbers.begin(), numbers.end());

	ofstream output("...\\FinalExam_Demo\\sorted.txt");
	if (output.fail()) {
		cout << "Error..";
		
		return -1;
	}

	for (int i = 0; i < numbers.size(); i++) output << numbers[i] << endl;

	output.close();
}