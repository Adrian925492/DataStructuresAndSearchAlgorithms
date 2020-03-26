#include <string>

int convertBinaryToDecimal(std::string input)
{
    int decNumber = 0;

    std::string::reverse_iterator it;

    int n = 0;

    for (it = input.rbegin(), n = 0l; it != input.rend(); ++it, ++n)
    {
        char c = *it;
        if (c == '1')
        {
            decNumber += pow(2,n);
        }
    }

    return decNumber;
}

std::string convertDecimaToBinary(int input)
{
    std::string output = "0";

    if (input > 0)
    {
        output = "";

        div_t dv{};

        dv.quot = input;

        do
        {
            dv = div(dv.quot, 2);
            output = std::to_string(dv.rem) + output;    //Concat divide rest and output string
        } while (dv.quot);
        
    }
    return output;      //Return output string
}