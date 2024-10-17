#include <cassert>
#include "../main/usefulFunctions.hpp"

void shouldTestToInt()
{
    int number=-1;
    oopTutorium::toInt('0',number);
    assert(number==0);
    number=-1;
    oopTutorium::toInt('9',number);
    assert(number==9);
    number=-1;
    oopTutorium::toInt('x',number);
    assert(number==-1);  
}

void shouldTestDecode(){
    std::string lines[] = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4de5f",
        "treb7uchet"
    };
    int expected[]{12,38,15,77};
    for (int i = 0; i < 4; ++i){
        assert(oopTutorium::decode(lines[i]) == expected[i]);
    }
    try{
        oopTutorium::decode("no digit");
        assert(false);
    }catch(std::invalid_argument&){

    }
}

int main()
{
    std::cout << "starting useful functions tests..." << std::endl;
    shouldTestToInt();
    shouldTestDecode();
    std::cout << "...finished" << std::endl;
    return 0;
}
