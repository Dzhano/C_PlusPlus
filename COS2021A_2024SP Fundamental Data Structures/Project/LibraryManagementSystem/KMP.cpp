#include <iostream>
#include <string>
#include <vector>


using namespace std;

class KMP {
private:
    vector<int> computeLPS(const string& pattern) {
        int M = pattern.length();
        vector<int> lps(M, 0);
        int len = 0;
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    int SearchString(const string& text, const string& pattern) {
        vector<pair<int, string>> matches;
        int N = text.length();
        int M = pattern.length();
        vector<int> lps = computeLPS(pattern);
        int i = 0;  // index for text
        int j = 0;  // index for pattern
        while (i < N) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            if (j == M) {
                matches.push_back(make_pair(i - j, pattern));
                j = lps[j - 1];
            }
            else if (i < N && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return matches.size();
    }
};