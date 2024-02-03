#include <iostream>

using namespace std;

class A {
public:
	A() { a = 0; b = 0; }
	int fa() { return b; }
	virtual int fb() { return a + b; }
	int a;
	int b;
};

class B : public A {
public:
	B() { a = 10; }
	int fa() { return a; }
	int fb() { return b; }
};

class C : public A {
public:
	C() { b = 20; }
	int fa() { return b; }
	int fb() { return a; }
};

class D {
public:
	D() { x.a = 30; x.b = 40; }
	virtual int fx() {
		A* g = &x; return g->fa() * g->fb(); // 40 * 40 = 1600
	}
	B x;
};

class E : public D {
public:
	E() { y.a = 50; y.b = 60; }
	int fx() {
		A* g = &y; return g->fa() * g->fb(); // 60 * 50 = 3000
	}
	C y;
};

void main()
{
	E e;
	D* d = &e;
	cout << d->fx() << "\n"; // 3000 It will only go through class E's fx().
}