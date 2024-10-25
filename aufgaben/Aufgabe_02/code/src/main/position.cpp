#include "position.hpp"

namespace oopTutorium
{
    void Position::set(const std::string &name, int x, int y)
    {
        this->name = name;
        this->x = x;
        this->y = y;
    }

    const std::string &Position::getName() const
    {
        return name;
    }

    int Position::getX() const
    {
        return x;
    }

    int Position::getY() const
    {
        return y;
    }
}