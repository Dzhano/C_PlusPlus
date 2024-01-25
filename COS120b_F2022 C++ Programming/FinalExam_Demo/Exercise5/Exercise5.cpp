#include <iostream>

using namespace std;

int main()
{
    string first, last;
    cout << "Please enter the first and last name: ";
    cin >> first >> last;
    cout << first.at(0) << " " << last[0] << endl
        << "The number of letters in the first name:" << first.length() << endl
        << "The number of letters in the Last name:" << last.size();
}