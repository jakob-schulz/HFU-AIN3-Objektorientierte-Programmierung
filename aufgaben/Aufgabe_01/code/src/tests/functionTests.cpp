#include <cassert>

#include "../main/usefulFunctions.hpp"

void shouldTestAlternatingSumofdigits()
{
    assert(alternatingSumofdigits(3) == 3);
    assert(alternatingSumofdigits(45) == -1);
    assert(alternatingSumofdigits(9944) == 0);
    assert(alternatingSumofdigits(67890) == -2);
    try
    {
        alternatingSumofdigits(0);
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        alternatingSumofdigits(-123);
        assert(false);
    }
    catch (...)
    {
    }
}

void shouldTestToInt()
{
    int number = 0;
    toInt('5', &number);
    assert(number == 5);
    toInt('0', &number);
    assert(number == 0);
    try
    {
        toInt('0', nullptr);
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        toInt('A', &number);
        assert(false);
    }
    catch(...)
    {
    }
    try
    {
        toInt('*', &number);
        assert(false);
    }
    catch(...)
    {
    }
    
}

void shouldTestDecode(){
    assert(decode("1xyz2") == 12);
    assert(decode("abc3pqr8ijk") == 38);
    assert(decode("x1y2z3v4w5q") == 15);
    assert(decode("hello7world") == 77);
    assert(decode("hello 124") == 14);
    try{
        decode("textwithoutnumber");
        assert(false);
    }catch(...){

    }
}

int main()
{
    std::cout << "starting..." << std::endl;
    shouldTestAlternatingSumofdigits();
    shouldTestToInt();
    shouldTestDecode();
    std::cout << "...finished" << std::endl;
    return 0;
}
