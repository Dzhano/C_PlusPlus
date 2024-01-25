#include <string>
#include <iostream>
using namespace std;

class Contact {
private:
	string name, email;
	long int number;
public:
	Contact() {
		setName("");
		setNumber(1);
		setEmail("");
	}

	Contact(string name, long int number, string email) {
		setName(name);
		setNumber(number);
		setEmail(email);
	}


	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setNumber(long int number) {
		this->number = number > 0 ? number : 1;
	}

	long int getNumber() {
		return number;
	}

	void setEmail(string email) {
		this->email = email;
	}

	string getEmail() {
		return email;
	}

	virtual void call() const;
};

class BlockedContact : public Contact {
private:
	bool blocked;
public:
	BlockedContact() : Contact() {
		setBlocked(false);
	}

	BlockedContact(string name, long int number, string email, bool blocked) : Contact(name, number, email) {
		setBlocked(blocked);
	}

	void setBlocked(bool blocked) {
		this->blocked = blocked;
	}

	bool getBlocked() {
		return blocked;
	}


	void call() {
		if (getBlocked) cout << "Currently blocked, cannot make a call." << endl;
		else cout << "Calling " << getName() << endl;
	}

	friend istream& operator>>(istream& in, BlockedContact& value) { // Overloading the ">>" operator
		string name;
		long int number;
		
		cout << "Enter the name of the contact: " << endl;
		in >> name;
		cout << "Enter the number of the contact: " << endl;
		in >> number;

		value.setName(name);
		value.setNumber(number);

		return in;
	}
};

class FavouriteContact : public Contact {
private:
	int order;
public:
	FavouriteContact() : Contact() {
		setOrder(1);
	}

	FavouriteContact(string name, long int number, string email, int order) : Contact(name, number, email) {
		setOrder(order);
	}

	void setOrder(int order) {
		this->order = order >= 1 && order <= 5 ? order : 1;
	}

	int getOrder() {
		return order;
	}


	void call() {
		cout << "Calling my " << getOrder() << " favourite contact - " << getName() << endl;
	}

	/*bool operator!=(const FavouriteContact& rhs) const {
		return getName() != *rhs.getName();
	}*/ // I do not have time to deal with this right now.
};