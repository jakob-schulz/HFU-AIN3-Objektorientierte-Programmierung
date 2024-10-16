#include <stdexcept>
#include "usefulFunctions.hpp"

bool oopTutorium::toInt(char c, int &theInt)
{
    if (c <= '9' && c >= '0')
    {
        theInt = c - '0';
        return true;
    }
    return false;
}

int oopTutorium::decode(const std::string line)
{
    int firstNumber = 0, lastNumber = 0;
    bool firstNumberFound = false;
    for (int position = 0; line[position] != 0; position++)
    {
        if (firstNumberFound)
        {
            oopTutorium::toInt(line[position], lastNumber);
        }
        else
        {
            if (oopTutorium::toInt(line[position], firstNumber))
            {
                lastNumber = firstNumber;
                firstNumberFound = true;
            }
        }
    }
    if (!firstNumberFound)
        throw std::invalid_argument("the text has no number");
    return firstNumber * 10 + lastNumber;
}