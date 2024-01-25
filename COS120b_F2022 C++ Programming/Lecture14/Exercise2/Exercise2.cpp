#include <iostream>
#include <string>
#include "Tuple.h"
using namespace std;

int main() {
    //Uncomment the exercise that you would like to test
    //ex1_13();
    int one = 2;
    double two = 1.618;
    char three = 'A';
    string four = "Ooo";

    Tuple<int, double> o1(one, two);
    Tuple<int, char> o2(one, three);
    Tuple<int, string> o3(one, four);
    Tuple<char, int> o4(three, one);
    // Tuple uses two template data types, but they do not have to be different
    Tuple<int, int> o5(one, one);

    cout << "The key and value for o1 are: " << o1.getKey() << " " << o1.getValue() << endl;
    cout << "The key and value for o2 are: " << o2.getKey() << " " << o2.getValue() << endl;
    cout << "The key and value for o3 are: " << o3.getKey() << " " << o3.getValue() << endl;
    cout << "The key and value for o4 are: " << o4.getKey() << " " << o4.getValue() << endl;
    cout << "The key and value for o5 are: " << o5.getKey() << " " << o5.getValue() << endl;
}