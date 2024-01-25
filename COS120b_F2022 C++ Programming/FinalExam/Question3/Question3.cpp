#include <iostream>

using namespace std;

class Car {
private:
    string model;
    string* brand;
    int year;
public:
    /*Car(string m, string b, int y) {
        model = m;
        brand = &b;
        year = y;
    }*/

    bool operator==(const Car& rhs) const {
        return model == rhs.model && *brand == *rhs.brand && year == rhs.year;
    }
};

int main()
{
    /*string a = "d";
    string b = "d";
    Car car1("Ford", a, 2003);
    Car car3("Ford", b, 2003);
    Car car2("Tesla", b, 2009);
    cout << (car1 == car2) << endl;
    cout << (car1 == car3) << endl;
    cout << (car1 == car1);*/
}