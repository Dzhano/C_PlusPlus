#include <string>
using namespace std;

class Vehicle {
private:
	double engineVolume, price;
	string color;
public:
	Vehicle() {
		setEngineVolume(1);
		setPrice(0);
		setColor("");
	}

	Vehicle(double engineVolume, double price, string color) {
		setEngineVolume(engineVolume);
		setPrice(price);
		setColor(color);
	}


	void setEngineVolume(double engineVolume) {
		if (engineVolume > 0)this->engineVolume = engineVolume;
		else this->engineVolume = 1;
	}

	double getEngineVolume() {
		return engineVolume;
	}

	void setPrice(double price) {
		if (price > -1)this->price = price;
		else this->price = 0;
	}

	double getPrice() {
		return price;
	}

	void setColor(string color) {
		this->color = color;
	}

	string getColor() {
		return color;
	}
};

class Car : public Vehicle {
private:
	string model;
public:
	Car() : Vehicle() {
		setModel("");
	}

	Car(double engineVolume, double price, string color, string model) : Vehicle(engineVolume, price, color) {
		setModel(model);
	}


	void setModel(string model) {
		this->model = model;
	}

	string getModel() {
		return model;
	}
};

class Bus : public Vehicle {
private:
	int numbersOfSeats;
public:
	Bus() : Vehicle() {
		setNumberOfSeats(1);
	}

	Bus(double engineVolume, double price, string color, int numbersOfSeats) : Vehicle(engineVolume, price, color) {
		setNumberOfSeats(numbersOfSeats);
	}


	void setNumberOfSeats(int numbersOfSeats) {
		if (numbersOfSeats > 0) this->numbersOfSeats = numbersOfSeats;
		else this->numbersOfSeats = 1;
	}

	int getNumberOfSeats() {
		return numbersOfSeats;
	}
};