#include <iostream>
#include "Student.h"

int main()
{
    Student students[5] = { {"Dzhano", , }, {"Alex", , }, {"Ivan", , }, {"Georgi", , }, {"Bobi", , } };
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Name: " << students[i].getName() << std::endl << "Final grade: " << students[i].getFinal() << std::endl;
        std::cout << std::endl;
    }
}