#include <iostream>

using namespace std;

class Book {
private:
    string name, author;
public:
    Book() {
        name = "";
        author = "";
    }

    Book(string n, string a) {
        name = n;
        author = a;
    }

    Book(const Book& other) {
        name = other.name;
        author = other.author;
    }
};

int main()
{
    Book book1;
    Book book2("Ready Player One", "Ernest Kline");
    Book book3(book2);
}