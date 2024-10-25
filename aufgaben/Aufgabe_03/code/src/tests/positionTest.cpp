#include "../main/position.hpp"
#include <cassert>

int main()
{
    std::cout<<"starting positionTest..."<<std::endl;

    std::string mordor = "Mordor";
    oopTutorium::Position position(mordor, 47, 11);

    assert(position.getName() == mordor);
    assert(position.getX() == 47);
    assert(position.getY() == 11);

    mordor[0] = 'X';
    assert(position.getName() == "Mordor"); //answer to the question: this test should validate that mordor[0] = 'X' doesn't change the name stored in the position object

    std::cout<<"...finished"<<std::endl;
}