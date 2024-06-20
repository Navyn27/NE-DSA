#include <iostream>
#include <string>

// To check whether an input string is a valid integer
bool isNumber(const string &input)
{
    for (char c : input)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}