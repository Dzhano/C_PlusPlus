#pragma once
#include <string>

class Student {
private:
	std::string name;
	double quizPoints, examPoints;
public:
	Student(std::string name, double quizPoints, double examPoints) {
		this->name = name;
		this->quizPoints = quizPoints;
		this->examPoints = examPoints;
	}

	std::string getName() {
		return name;
	}

	double getFinal() {
		return 0.4 * quizPoints + 0.6 * examPoints;
	}
};