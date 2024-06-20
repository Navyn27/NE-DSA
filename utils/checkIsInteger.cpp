#include <iostream>
#include <string>

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