#include <iostream>

using namespace std;

class BaseStudent {
public:
    virtual void displayGrade() const = 0; // Adding "= 0" so that the method and the class become abstract.
};

class Student : public BaseStudent {
private:
	string name;
	double exams, quizzes;
public:
	Student() {
        setName("");
        setExams(0);
        setQuizzes(0);
	}

	Student(string name, double exams, double quizzes) {
        setName(name);
        setExams(exams);
        setQuizzes(quizzes);
	}

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setExams(int e) {
        exams = e >= 0 and e <= 100 ? e : 0;
    }

    double getExams() const {
        return exams;
    }
   
    void setQuizzes(int q) {
        quizzes = q >= 0 and q <= 100 ? q : 0;
    }

    double getQuizzes() const {
        return quizzes;
    }


    double getFinalGrade() const {
        return 0.4 * quizzes + 0.6 * exams;
    }

    bool operator<(const Student& obj) const {
        return getFinalGrade() < obj.getFinalGrade();
    }

    void displayGrade() const {
        double grade = getFinalGrade();
        if (grade >= 90) {
            cout << "A" << endl;
        }
        else if (grade >= 80) {
            cout << "B" << endl;
        }
        else if (grade >= 70) {
            cout << "C" << endl;
        }
        else if (grade >= 60) {
            cout << "D" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
};

class PFStudent : public Student {
public:
    PFStudent() : Student(){}
    PFStudent(string name, double exams, double quizzes) : Student(name, exams, quizzes) {}

    void displayGrade() const {
        if (getFinalGrade() >= 60) {
            cout << "P" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
};