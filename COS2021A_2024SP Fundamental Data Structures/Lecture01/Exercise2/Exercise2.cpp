#include <iostream>

using namespace std;

string* name() {
	return new string("hello");
}

void main() {
	string* strName = name();
	int x = (*strName)[3] - (*strName)[1];
	delete strName; // even though it deletes strName, the memory of strDelete is set to default
	int y = sizeof(strName); // undefined behavior
	cout << x << y << endl; // 78
}