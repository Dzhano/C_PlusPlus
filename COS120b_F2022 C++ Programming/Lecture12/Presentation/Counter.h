#pragma once

class Counter {
    //private: 
    int count, maxValue;
public:
    Counter();
    Counter(int);
    Counter(int, int);

    int getCount() const; //{ return count; }
    int getMaxValue() const;
    void setCount(int);
    void setMaxValue(int);
    void increment();
    void decrement();
};


Counter c;
Counter c2(1);
Counter c3(1, 2);