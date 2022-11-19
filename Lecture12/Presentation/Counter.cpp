#include <iostream>
#include "Counter.h"

Counter::Counter() {
    count = 0;
    maxValue = 100;
}

Counter::Counter(int maxValue) {
    count = 0; // setCount(0);
    setMaxValue(maxValue); // this->maxValue = maxValue;
}
Counter::Counter(int maxValue, int count) {
    setCount(count);
    setMaxValue(maxValue); // this->maxValue = maxValue;
}



int Counter::getCount() const {
    return count;
}

int Counter::getMaxValue() const {
    return maxValue;
}

void Counter::setCount(int set) {
    /*if (set > 0) count = set;
    else count = 0;*/
    count = set > 0 ? set : 0;
}

void Counter::setMaxValue(int set) {
    maxValue = set > 0 ? set : 100;
}

void Counter::increment() {
    if (count < maxValue) count++;
    else std::cout << "Error: Cannot go beyond maxValue!" << std::endl;
}

void Counter::decrement() {
    if (count > 0) count--;
    else std::cout << "Error: Cannot go below 0!" << std::endl;
}