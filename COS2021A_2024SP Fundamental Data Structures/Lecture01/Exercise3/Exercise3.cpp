#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ChecksumChecker {
private:
    string filename;

public:
    // Constructor
    ChecksumChecker(const string& filename) : filename(filename) {}

    // Method to compute checksum
    uint32_t compute() {
        ifstream file(filename, ios::in);

        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return 0; // Return 0 as an error code
        }

        uint32_t checksum = 0;
        char ch;

        // Read characters from the file and add their ASCII values to the checksum
        while (file.get(ch)) {
            checksum += static_cast<uint32_t>(ch);  // Add ASCII value to checksum
        }

        file.close();
        return checksum;
    }
};

int main() {
    // Test the ChecksumChecker class
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    ChecksumChecker checksumChecker(filename);

    uint32_t checksum = checksumChecker.compute();

    if (checksum != 0) {
        cout << "Checksum for file " << filename << ": " << checksum << endl;
    }

    return 0;
}
