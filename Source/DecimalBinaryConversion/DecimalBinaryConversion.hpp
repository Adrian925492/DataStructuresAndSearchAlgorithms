#include <string>

int convertBinaryToDecimal(std::string input)
{
    int decNumber = 0;

    std::string::reverse_iterator it;   //Create reverse iterator for string

    int n = 0;

    for (it = input.rbegin(), n = 0; it != input.rend(); ++it, ++n)    //Iterate threw string. Start from end up to begin (rbegin())
    {
        char c = *it;   //Get value pointed by iterator
        if (c == '1')   //If the value is 1
        {
            decNumber += pow(2,n);  //Calculate power of the value
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

        div_t dv{};     //Division results place

        dv.quot = input;    //Division quote init

        do
        {
            dv = div(dv.quot, 2);   //Make division
            output = std::to_string(dv.rem) + output;    //Concat divide rest and output string
        } while (dv.quot);  //Do divisions untill quote will be nonzero (untill can be dvided)
        
    }
    return output;      //Return output string
}