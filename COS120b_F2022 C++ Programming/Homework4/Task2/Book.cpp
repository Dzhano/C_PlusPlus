#include <iostream> // Allowing us to use std::cout
using namespace std;

class Book {
private:
	string name, author;
	int pages;
public:
	Book() { // Empty constructor
		setName("");    // Entering default values
		setAuthor("");
		setPages(1);
	}

	Book(string name, string author, int pages) { // Constructor with input data
		setName(name); // Entering values
		setAuthor(author);
		setPages(pages);
	}


	void setName(string name) {
		this->name = name; // Giving the book a name.
	}

	string getName() {
		return name; // Learning the book's name.
	}

	void setAuthor(string author) {
		this->author = author; // Giving the book an author.
	}

	string getAuthor() {
		return author; // Learning the book's author.
	}

	void setPages(int pages) {
		this->pages = pages > 0 ? pages : 1; // Setting how many pages the book will have.
	}

	int getPages() {
		return pages; // Learing the book's number of pages
	}

	virtual void type() const {} // Learing the type of the book. In this case nothing will show, as there is no requirement for this case.

	bool operator==(const Book& rhs) const {
		return name == rhs.name && author == rhs.author ? true : false; // CTesting if the current book is the same as the other one.
	}
};

class ChildrenBook : public Book {
private:
	int ageAppropriate;
public:
	ChildrenBook() : Book() { // Empty constructor
		setAgeAppropriate(1); // Entering default values
	}

	ChildrenBook(string name, string author, int pages, int ageAppropriate) : Book(name, author, pages) { // Constructor with input data
		setAgeAppropriate(ageAppropriate);
	}


	void setAgeAppropriate(int ageAppropriate) {
		this->ageAppropriate = ageAppropriate > 0 ? ageAppropriate : 1; // Setting what is the appropriate age for children to read the book.
	}

	int getAgeAppropriate() {
		return ageAppropriate; // Learing what is the appropriate age for children to read the book.
	}


	void type() {
		cout << "Children book for "<< getAgeAppropriate() <<" and older" << endl; // Describing what is the type of the book and how old should children be to read it.
	}

	friend istream& operator>>(istream& in, ChildrenBook& value) { // Overloading the ">>" operator
		string bookName, firstName, lastName;
		int pages, age;

		// Asking a question after each variable so the user can know what to enter
		cout << "Enter book's name: ";
		in >> bookName;
		cout << "Enter author's full name: ";
		in >> firstName >> lastName;
		cout << "Enter number of pages: ";
		in >> pages;
		cout << "Enter appropriate age for children to read it: ";
		in >> age;

		// Setting the values
		value.setName(bookName);
		value.setAuthor(firstName + " " + lastName);
		value.setPages(pages);
		value.setAgeAppropriate(age);
		
		return in;
	}
};

class SeriousBook : public Book {
private:
	string genre;
public:
	SeriousBook() : Book() { // Empty constructor
		setGenre(""); // Entering default values
	}

	SeriousBook(string name, string author, int pages, string genre) : Book(name, author, pages) { // Constructor with input data
		setGenre(genre);
	}


	void setGenre(string genre) {
		this->genre = genre; // Setting the genre of the book.
	}

	string getGenre() {
		return genre; // Learing the genre of the book.
	}


	void type() {
		cout << "Serious book, genre: " << getGenre() << endl; // Describing what is the type of the book and what is its genre.
	}
};