#include <iostream>

int main()
{
    
    int n;
    float input, sum = 0;

    //Option 1
    std::cout << "How many times would you want to input numbers?\n";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        sum += input;
    }

    /*//Option 2
    bool done = false;
    n = 0; sum = 0;
    while (true)
    {
        std::cout << "Enter a number or 0 to stop: ";
        std::cin >> input;
        if (input == 0) break;
        sum += input;
        n++;
    }*/


    if (n != 0) std::cout << "The average of the numbers is " << sum / n;
}