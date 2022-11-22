// The test Diver class (cpp) with main function

#include <iostream> // Allowing us to use std::cout
#include <fstream> // Allowing us to use ifstream
#include "Student.h" // Connecting the header file

int main()
{
    // Open the file
    std::ifstream input("...\\Homework3\\Task1\\students.txt"); // Since the task is going to be tested on another computer, but mine, the program address is going to be different than the one on my laptop.

    //Check whether the file was opened successfully
    if (input.fail()) {
        std::cout << "Failed to open the file!" << std::endl;
        return -1; // If the file is not open successfully, the program gets terminated immediatelly.
    }

    // Process the file
    std::string name; // The name of the current student
    std::string major; // The major of the current student
    int age; // The age of the current student

    int counter = 1;
    Student oldest;
    Student youngest;

    while (!input.eof()) // Checking whether there are any lines in the file and, if there are, the loop will go through all of them.
    {
        getline(input, name, '#'); // the name by stopping at the '$' character
        input >> major >> age; // the price per unit and the quantity.
        input.ignore(100, '\n'); // After that we make the progrma to skip the sign for new line so it does get included in the name of the next student.

        Student student(name, major, age);
        student.display();

        if (counter == 1) {
            youngest.setName(student.getName());
            youngest.setMajor(student.getMajor());
            youngest.setAge(student.getAge());

            oldest.setName(student.getName());
            oldest.setMajor(student.getMajor());
            oldest.setAge(student.getAge());

            counter++;
        }
        else {
            if (student.getAge() < youngest.getAge())
            {
                youngest.setName(student.getName());
                youngest.setMajor(student.getMajor());
                youngest.setAge(student.getAge());
            }
            else if (student.getAge() > oldest.getAge()) {
                oldest.setName(student.getName());
                oldest.setMajor(student.getMajor());
                oldest.setAge(student.getAge());
            }
        }
    }

    // Close the file
    input.close();

    // The final output where we describe the complete total price which we have to pay for.
    std::cout << "The youngest student is " << youngest.getName() << " and the oldest is " << oldest.getName() << ".";
}