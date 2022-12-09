#include <string>
using namespace std;

class College {
private:
	string name;
	int numStudents, numFaculty;
public:
	College() {
		setName("");
		setNumStudents(1);
		setNumFaculty(1);
	}

	College(string name, int numStudents, int numFaculty) {
		setName(name);
		setNumStudents(numStudents);
		setNumFaculty(numFaculty);
	}


	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setNumStudents(int numStudents) {
		this->numStudents = numStudents > 0 ? numStudents : 1;
	}

	int getNumStudents() {
		return numStudents;
	}

	void setNumFaculty(int numFaculty) {
		this->numFaculty = numFaculty > 0 ? numFaculty : 1;
	}

	int getNumFaculty() {
		return numFaculty;
	}


	double SFRatio() {
		return (double)getNumStudents() / getNumFaculty();
	}
};

class CollegeRatios : public College {
public:
	CollegeRatios() : College() {}
	CollegeRatios(string name, int numStudents, int numFaculty) : College(name, numStudents, numFaculty) {}

	double FSRatio() {
		return (double)getNumFaculty() / getNumStudents();
	}
};