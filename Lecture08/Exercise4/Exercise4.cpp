#include <iostream>
#include <cstring>

int get_position(char text[], char pat[]);

int main()
{

}

int get_position(char text[], char pat[])
{
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == pat[0])
        {
            bool correct = true;
            for (int u = 0; u < strlen(pat); u++)
                if (text[i + u] != pat[u])
                {
                    correct = false;
                    break;
                }
            if (correct) return i;
        }
    return -1;
}