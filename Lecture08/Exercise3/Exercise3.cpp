#include <iostream>
#include <cstring>

bool is_valid_name(char str[]);

int main()
{

}

bool is_valid_name(char str[])
{
    if (strlen(str) >= 4 && strlen(str) <= 20 && isupper(str[0]))
    {
        for (int i = 1; i < strlen(str); i++)
            if (!islower(str[i])) return false;
        return true;
    }
    else return false;
}