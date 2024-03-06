#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) { // My solution
    vector<int> result;
    stack<int> values;

    for (const string& operation : operations) {
        stringstream strs(operation);
        int operationType;
        strs >> operationType;

        if (operationType == 1) {
            // Type 1: Push element onto stack
            int value;
            strs >> value;
            values.push(value);
        }
        else if (operationType == 2) {
            // Type 2: Pop element from stack
            if (!values.empty()) values.pop();
        }
        else if (operationType == 3) {
            // Type 3: Get maximum element from stack
            if (!values.empty()) {
                stack<int> tempStack = values;
                int stackMax = tempStack.top();
                while (!tempStack.empty()) {
                    if (stackMax < tempStack.top()) stackMax = tempStack.top();
                    tempStack.pop();
                }
                result.push_back(stackMax);
            }
        }
    }

    return result;
}

/*
vector<int> getMax(vector<string> operations) { // ChatGPT solution
    vector<int> result;
    stack<int> stackValues;
    stack<int> stackMax;

    for (const string& op : operations) {
        stringstream ss(op);
        int operationType;
        ss >> operationType;

        if (operationType == 1) {
            // Type 1: Push element onto stack
            int value;
            ss >> value;
            stackValues.push(value);
            if (stackMax.empty() || value >= stackMax.top()) {
                stackMax.push(value);
            }
        }
        else if (operationType == 2) {
            // Type 2: Pop element from stack
            int popped = stackValues.top();
            stackValues.pop();
            if (popped == stackMax.top()) {
                stackMax.pop();
            }
        }
        else if (operationType == 3) {
            // Type 3: Get maximum element from stack
            if (!stackMax.empty()) {
                result.push_back(stackMax.top());
            }
        }
    }

    return result;
}
*/


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

