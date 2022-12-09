#include <iostream>
#include "Book.cpp"
using namespace std;

int main()
{
	// Testing the constructors.
	Book emptyBook;
	Book book1("Harmanli", "Dzhano Mihaylov", 200);

	ChildrenBook emptyChildrenBook;
	ChildrenBook childrenBook1("Harry Potter", "J. K. Rowling", 3407, 7);

	SeriousBook emptySeriousBook;
	SeriousBook seriousBook1("Rich Dad, Poor Dad", "Robert T. Kiyosaki", 336, "Economics");

	// Testing the "==" operator
	cout << (emptyBook == emptyBook) << endl;  // True since it is the same book.
	cout << (emptyBook == childrenBook1) << endl; // False
	cout << (emptyBook == emptyChildrenBook) << endl; // True, even though their types are different

	cout << endl; // Dividing for a better view in the command window

	// Testing setters
	Book book2;
	book2.setAuthor("Ivan Vazov");
	book2.setName("Under the Yoke");
	book2.setPages(120);

	ChildrenBook childrenBook2;
	childrenBook2.setName("How to train your dragon");
	childrenBook2.setAuthor("Cressida Cowell");
	childrenBook2.setPages(600);
	childrenBook2.setAgeAppropriate(9);

	SeriousBook seriousBook2;
	seriousBook2.setName("Elon Musk");
	seriousBook2.setAuthor("Ashlee Vance");
	seriousBook2.setPages(199);
	seriousBook2.setGenre("Authobiography");

	// Testing the polymorphism
	Book childrenBook3 = childrenBook2;
	Book seriousBook3 = seriousBook1;

	// Testing "friend istream& operator>>(istream& in, ChildrenBook& value)" // Overloading the ">>" operator for ChildrenBook class
	ChildrenBook childrenBook4;
	cin >> childrenBook4; // Works on an empty ChildrenBook
	//cin >> childrenBook2; // Works on a full Children
	// cin >> childrenBook3; // It does not work if the class is Children but it is read as Book

	// Testing the getters          There are too many so I will test at least one of a type.
	cout << "EmptyBook's name: " << emptyBook.getName() << endl;
	cout << "EmptyBook's author: " << emptyBook.getAuthor() << endl;
	cout << "EmptyBook's pages: " << emptyBook.getPages() << endl;
	cout << "Book1's name: " << book1.getName() << endl;
	cout << "Book1's author: " << book1.getAuthor() << endl;
	cout << "Book1's pages: " << book1.getPages() << endl;
	cout << "Book2's name: " << book2.getName() << endl;
	cout << "Book2's author: " << book2.getAuthor() << endl;
	cout << "Book2's pages: " << book2.getPages() << endl;
	cout << "EmptyChildrenBook's name: " << emptyChildrenBook.getName() << endl;
	cout << "EmptyChildrenBook's author: " << emptyChildrenBook.getAuthor() << endl;
	cout << "EmptyChildrenBook's pages: " << emptyChildrenBook.getPages() << endl;
	cout << "EmptyChildrenBook's ageAppropriate: " << emptyChildrenBook.getAgeAppropriate() << endl;
	cout << "ChildrenBook1's name: " << childrenBook1.getName() << endl;
	cout << "ChildrenBook1's author: " << childrenBook1.getAuthor() << endl;
	cout << "ChildrenBook1's pages: " << childrenBook1.getPages() << endl;
	cout << "ChildrenBook1's ageAppropriate: " << childrenBook1.getAgeAppropriate() << endl;
	cout << "ChildrenBook4's name: " << childrenBook4.getName() << endl;
	cout << "ChildrenBook4's author: " << childrenBook4.getAuthor() << endl;
	cout << "ChildrenBook4's pages: " << childrenBook4.getPages() << endl;
	cout << "ChildrenBook4's ageAppropriate: " << childrenBook4.getAgeAppropriate() << endl;
	cout << "EmptySeriousBook's name: " << emptySeriousBook.getName() << endl;
	cout << "EmptySeriousBook's author: " << emptySeriousBook.getAuthor() << endl;
	cout << "EmptySeriousBook's pages: " << emptySeriousBook.getPages() << endl;
	cout << "EmptySeriousBook's genre: " << emptySeriousBook.getGenre() << endl;
	cout << "SeriousBook1's name: " << seriousBook1.getName() << endl;
	cout << "SeriousBook1's author: " << seriousBook1.getAuthor() << endl;
	cout << "SeriousBook1's pages: " << seriousBook1.getPages() << endl;
	cout << "SeriousBook1's genre: " << seriousBook1.getGenre() << endl;

	cout << endl; // Dividing for a better view in the command window

	// Testing the "Type()" function
	emptyBook.type(); // Nothing
	book1.type(); // Nothing
	book2.type(); // Nothing
	emptyChildrenBook.type(); // Default
	childrenBook1.type();
	childrenBook2.type();
	childrenBook3.type(); // Nothing since it is read as a Book, but the data is sill inside.
	childrenBook4.type();
	emptySeriousBook.type(); // Default
	seriousBook1.type();
	seriousBook2.type();
	seriousBook3.type(); // Nothing since it is read as a Book, but the data is still inside.
}