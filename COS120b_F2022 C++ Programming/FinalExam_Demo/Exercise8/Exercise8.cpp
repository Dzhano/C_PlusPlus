#include <iostream>
#include "Student.cpp"

int main()
{
    Student student("Dzhano Mihaylov", 100, 100);
    student.displayGrade();

    PFStudent student2("Yoana Stancheva", 89, 92);
    student2.displayGrade();
}