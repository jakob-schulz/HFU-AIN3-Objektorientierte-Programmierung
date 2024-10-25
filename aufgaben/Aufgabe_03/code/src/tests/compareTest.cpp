#include "../main/position.hpp"
#include <cassert>

void compareTest()
{
    std::string mordor = "Mordor";
    oopTutorium::Position position(mordor, 47, 11);
    assert(position.compare(position) == 0);
    oopTutorium::Position position_name("zordor", 47, 11);
    oopTutorium::Position position_x(mordor, 48, 11);
    oopTutorium::Position position_y(mordor, 47, 12);
    assert(position.compare(position_name) < 0);
    assert(position.compare(position_x) < 0);
    assert(position.compare(position_y) < 0);
    assert(position_name.compare(position) > 0);
    assert(position_x.compare(position) > 0);
    assert(position_y.compare(position) > 0);
}

int main(){
    std::cout<<"starting compareTest..."<<std::endl;
    compareTest();
    std::cout<<"...finished"<<std::endl;
}
