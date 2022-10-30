#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    // Open the files
    ifstream input("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise7\\allnames.txt");
    ofstream output("D:\\Classes\\COS 120 C++ Programming\\C_PlusPlus\\Lecture10\\Exercise8\\copyofallnames.txt");

    //Check whether the files were opened successfully
    if (input.fail()) {
        cout << "Cannot open the all names file." << endl;
        return -1;
    }
    if (output.fail()) {
        cout << "Cannot open the copy names file." << endl;
        return -1;
    }

    // Process the files
    string firstname, lastname;
    string names[6], names2[6];
    int index = 0;

    while (!input.eof()) {
        input >> firstname >> lastname;
        names[index++] = firstname + " " + lastname;

        cout << names[index - 1] << endl;
    }

    index = 0;
    for (int i = 0; i < 6; i++)
    {
        bool add = true;
        for (int j = 0; j < 6; j++)
        {
            if (names[i] == names2[j]) add = false;
        }
        names2[index++] = names[i];
        if (add) output << names[i] << endl;
    }

    // Close the files
    input.close();
    output.close();
}