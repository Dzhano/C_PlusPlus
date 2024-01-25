#include <iostream>

int palindrome (std::string);

int main()
{
    std::cout << palindrome("level") << std::endl;
    std::cout << palindrome("deed") << std::endl;
    std::cout << palindrome("mom") << std::endl;
    std::cout << palindrome("handsome") << std::endl;
}

int palindrome(std::string word)
{
    if (word.length() == 0 || word.length() == 1) return 1;
    if (word[0] == word[word.length() - 1])
    {
        word.erase(0, 1);
        word.erase(word.length() - 1, 1);
        return palindrome(word);
    }
    else return 0;
}