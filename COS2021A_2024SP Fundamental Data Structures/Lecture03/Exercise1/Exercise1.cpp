#include <iostream>

using namespace std;

class A {
public:
    A() { a = 10; b = 10; c = 10; }
    void BB(int x, int y, int z) {
        a = x; b = y; c = z;
    }
    virtual void CC(int x, int y, int z) {
        a = z; b = y; c = x;
    }
    void DD(int x, int y, int z) {
        a = y; b = x; c = z;
    }
    void PP() { cout << a << '/' << b << '/' << c; }
protected:
    int a; int b; int c;
};

class B : public A {
public:
    B() { a += 100; b += 100; c += 100; }
    void BB(int x, int y, int z) {
        a -= x; b -= y; c -= z;
    }
    void CC(int x, int y, int z) {
        a -= z; b -= y; c -= x;
    }
    void DD(int x, int y, int z) {
        a -= y; b -= x; c -= z;
    }
};

class C : public B {
public:
    C() { a += 1000; b += 1000; c += 1000; }
    void BB(int x, int y, int z) {
        a += x; b += y; c += z;
    }
    void CC(int x, int y, int z) {
        a += z; b += y; c += x;
    }
    void DD(int x, int y, int z) {
        a += y; b += x; c += z;
    }
};

void main()
{
    C x; // a = 1110, b = 1110, c = 1110
    A* ptr = &x;
    ptr->BB(2, 3, 4); // a = 2, b = 3, c = 4
    ptr->CC(10, 20, 30); // a = 32, b = 23, c = 14
    ptr->DD(90, 50, 10); // a = 50, b = 90, c = 10
    x.PP(); // 50/90/10
}