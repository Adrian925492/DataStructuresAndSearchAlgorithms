#include <string>
#include <algorithm>

/* Anagram detects - two words are anagrams if they are done using same letters and same number of letters.
To check anagrams, we have to convert are letters to same letter size (big or small), than remove special signs, like
spaces, than sort it. If sorted strings are equal - they are anagrams */

bool CheckAnagram(std::string string1, std::string string2)
{
    std::transform(string1.begin(), string1.end(), string1.begin(), ::toupper);     //Convert all strings to uppercase (letter size no matters)
    std::transform(string2.begin(), string2.end(), string2.begin(), ::toupper);

    string1.erase(std::remove(string1.begin(), string1.end(), ' '), string1.end()); //Remove spaces from both strings
    string2.erase(std::remove(string2.begin(), string2.end(), ' '), string2.end());   

    std::sort(string1.begin(), string1.end());      //Sort both strings
    std::sort(string2.begin(), string2.end());

    return string1 == string2;  //Check if sorted strings are equal
}