#include <cassert>
#include "../main/position.hpp"

void shouldTestPosition()
{
    oopTutorium::Position mordor;
    mordor.set("Mordor", 3, 4);
    assert(mordor.getX() == 3);
    assert(mordor.getY() == 4);
    assert(mordor.getName() == "Mordor");
    mordor.set("noname", -234, 0);
    assert(mordor.getX() == -234);
    assert(mordor.getY() == 0);
    assert(mordor.getName() == "noname");
    mordor.set("", 1, 2);
    assert(mordor.getName() == "");
}

int main()
{
    std::cout << "starting position tests..." << std::endl;
    shouldTestPosition();
    std::cout << "...finished" << std::endl;
}