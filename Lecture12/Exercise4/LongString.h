#pragma once
#include <string>

class LongString {
private:
    std::string value;
public:
    LongString(std::string s);
    int length = value.length();

    char get(int);
    void addString(const LongString&);
};