#include <string>
#include <algorithm>

/* Palindrome detects - the word is palindrome if it can be readen from begining and from end. It means it has same 
sign sequence in two sides. To check if the word is palindrome we have to check pairs of signs, starting from last and
first one, up to middle ones. */

bool CheckPalindrome(std::string string1)
{
    std::transform(string1.begin(), string1.end(), string1.begin(), ::toupper);     //Convert string to uppercase (letter size no matters)

    string1.erase(std::remove(string1.begin(), string1.end(), ' '), string1.end()); //Remove spaces from string

    return std::equal(string1.begin(), string1.begin() + string1.size()/2, string1.rbegin());  //Check signs pairs
}