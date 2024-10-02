#include <stdexcept>

int alternatingSumofdigits(int number){
    if(number <= 0)
    {
        throw std::invalid_argument(std::to_string(number) + " is not a natural number");
    }

    int lengthOfNumber = 0;
    int DetermingLengthOfNumber = number;
    int result = 0;
    int indicator = 0; 
    
    //determing the length of the number
    while(DetermingLengthOfNumber != 0)
    {
        DetermingLengthOfNumber = DetermingLengthOfNumber / 10; 
        lengthOfNumber++;
    }
    
    //define whether the last digit is even or odd (depends on the length of the word)
    if(lengthOfNumber % 2 == 0)
    {
        indicator = -1; 
    }
    else
    {
        indicator = 1;
    }

    //calculating the alternating sum of digits from right to left
    while (number != 0)
    {
        result = result + indicator * (number % 10);
        number = number / 10;
        indicator = -indicator;
    }
    
    return result;
}

void toInt(char c, int *theInt)
{
    if(theInt == nullptr)
    {
        throw std::invalid_argument("the pointer is null");
    }

    if(c <= '9' && c >= '0')
    {
        *theInt = c - '0';
    }
    else
    {
        throw std::invalid_argument("your digit isn't a number");
    }
}


int decode(const char *line){
    int firstNumber = 0, lastNumber = 0;
    bool firstNumberFound = false;
    for(int position = 0; line[position] != 0; position++){
        try{
            if(firstNumberFound)
                toInt(line[position], &lastNumber);
            else{
                toInt(line[position], &firstNumber);
                lastNumber = firstNumber;
                firstNumberFound = true;
            }
        }catch(...){}
    }
    if(!firstNumber)
        throw std::invalid_argument("the text has no number");
    return firstNumber * 10 + lastNumber;
}