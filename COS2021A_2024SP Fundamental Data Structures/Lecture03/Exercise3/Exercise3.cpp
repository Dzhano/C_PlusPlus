#include <iostream>

using namespace std;

class Student {
public:
    Student() { e = 0; q = 0; h = 0; name = "N/A"; }
    void score(double x, double y, double z) {
        e = x; q = y; h = z;
    }
    virtual void grade() = 0;
protected:
    string name;
    double e; double q; double h;
};

class A : public Student {
public:
    A(double x, double y, double z, string w)
    {
        e = x; q = y; h = z; name = w;
    }
    void score(double x, double y, double z) // not touched
    {
        e = +x; q = +y; h = +z;
    }
    void grade()
    {
        cout << name << 0.4 * e + 0.4 * q + 0.2 * h;
    }
};

class B : public Student {
public:
    B(double x, double y, double z, string w)
    {
        e = x; q = y; h = z; name = w;
    }
    void score(double x, double y, double z) // not touched
    {
        e = -x; q = -y; h = -z;
    }
    void grade()
    {
        cout << name << 0.5 * e + 0.4 * q + 0.1 * h;
    }
};

class C : public Student {
public:
    C(double x, double y, double z, string w)
    {
        e = x; q = y; h = z; name = w;
    }
    void score(double x, double y, double z) // not touched
    {
        e = +x; q = -y; h = +z;
    }
    void grade()
    {
        cout << name << 0.6 * e + 0.2 * q + 0.2 * h;
    }
};


void main()
{
    A x(30.0, 30.0, 30.0, "A");
    B y(10.0, 20.0, 30.0, "B");
    C z(20.0, 40.0, 60.0, "C");

    Student* p[3] = { &x, &y, &z };

    double exam = 50;
    double quiz = 30;
    double hw = 20;

    for (int i = 0; i < 3; i++) {
        p[i]->score(exam, quiz, hw);
        p[i]->grade();  // i = 0: A36
                        // i = 1: B39
                        // i = 2: C40
        cout << endl;
    }
}