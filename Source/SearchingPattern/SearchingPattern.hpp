#include <string>
#include <vector>

std::vector<int> patternSearch(std::string inputString, std::string target)
{
    std::vector<int> output;

    for (int i = 0; i < static_cast<int>(inputString.size()); ++i)
    {
        int j = 0;      //target string counter

        for (j = 0; j < static_cast<int>(target.size()); ++j)
        {
            if (inputString[i + j] != target[j])
            {
                break;      //Break lop if any element do not fits
            }
        }

        if (j == static_cast<int>(target.size())) //If found
        {
            output.push_back(i);    //Add to results list
        }
    }

    return output;
}