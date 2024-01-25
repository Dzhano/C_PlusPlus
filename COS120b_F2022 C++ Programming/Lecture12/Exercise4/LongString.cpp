#include "LongString.h"

LongString::LongString(std::string s) {
    std::string value = s;
}

// int LongString::length = value.length();  // not working

char LongString::get(int p) {
    return p >= length || p < 0 ? value[p] : ' ';
}

void LongString::addString(const LongString& s) {
    value += s.value;
}