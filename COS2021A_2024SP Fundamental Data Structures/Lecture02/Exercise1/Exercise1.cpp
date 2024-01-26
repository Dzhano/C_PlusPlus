#include <iostream>

using namespace std;

int main()
{

}

class Product {
private:
    string name, description;
    int code, quantity;
    double cost;

public:
    //Constructors
    Product() {
        this->name = "";
        this->description = "";
        this->code = 0;
        this->quantity = 0;
        this->cost = 0;
    }

    Product(string name, string description, int code, int quantity, double cost) {
        this->name = name;
        this->description = description;
        this->code = code;
        this->quantity = quantity;
        this->cost = cost;
    }

    Product(const Product& other) { // Copy constructor
        name = other.name;
        description = other.description;
        code = other.code;
        quantity = other.quantity;
        cost = other.cost;
    }


    bool operator==(const Product& other) const {
        return code == other.code;
    }

    friend ostream& operator<<(ostream& out, const Product& product) {
        out << "Name: " << product.name << endl;
        out << "Description: " << product.description << endl;
        out << "Code: " << product.code << endl;
        out << "Quantity: " << product.quantity << endl;
        out << "Cost: " << product.cost << endl;
        return out;
    }
};