#include"position.hpp"

void oopTutorium::Position::set(const std::string &name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}

const std::string &oopTutorium::Position::getName() const{
    return name;
}

int oopTutorium::Position::getX() const{
    return x;
}

int oopTutorium::Position::getY() const{
    return y;
}