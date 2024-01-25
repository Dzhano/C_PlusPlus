#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    // Open the files
    ifstream input1("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise7\\names1.txt");
    ifstream input2("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise7\\names2.txt");
    ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise7\\allnames.txt");

    //Check whether the files were opened successfully
    if (input1.fail()) {
        cout << "Cannot open the first name file." << endl;
        return -1;
    }
    if (input2.fail()) {
        cout << "Cannot open the second name file." << endl;
        return -1;
    }
    if (output.fail()) {
        cout << "Cannot open the output name file." << endl;
        return -1;
    }

    // Process the files
    string firstname, lastname;
    string names[6];
    int index = 0;

    while (index < 3) {
        input1 >> firstname >> lastname;
        names[index++] = firstname + " " + lastname;
    }
    while (index < 6) {
        input2 >> firstname >> lastname;
        names[index++] = firstname + " " + lastname;
    }
    // sort(begin(names), end(names));  // I couldn't figure out how to sort the names.

    for (int i = 0; i < 6; i++) 
        output << names[i] << endl;

    // Close the files
    input1.close();
    input2.close();
    output.close();
}