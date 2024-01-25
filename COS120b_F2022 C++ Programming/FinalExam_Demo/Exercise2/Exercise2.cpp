#include <iostream>
#include <fstream>

using namespace std;

int main()
{

}

void calc(int arr[][3], int rows, int cols) {
    ofstream output("...\\FinalExam_Demo\\output.txt");
    if (output.fail()) {
        cout << "Error..." << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 3 == 0 && arr[i][j] % 4 == 0)
                sum += arr[i][j];
        }
        output << sum << endl;
    }
    output.close();
}