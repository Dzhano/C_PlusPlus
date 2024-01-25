#include <iostream>

using namespace std;

string* name() {
	return new string("hello");
}

void main() {
	string* strName = name();
	int x = (*strName)[3] - (*strName)[1];
	delete strName;
	int y = sizeof(strName);
	cout << x << y << endl; // 78
}