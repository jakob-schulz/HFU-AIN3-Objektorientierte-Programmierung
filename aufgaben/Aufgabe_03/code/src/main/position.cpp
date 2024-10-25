#include "position.hpp"

namespace oopTutorium
{

    Position::Position(const std::string &name, int x, int y) : name(name), x(x), y(y)
    {
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

    int Position::compare(const Position &position)
    {
        if (this->name.compare(position.getName()) < 0)
        {
            return -1;
        }
        if (this->name.compare(position.getName()) > 0)
        {
            return 1;
        }
        if (this->x < position.getX())
        {
            return -1;
        }
        if (this->x > position.getX())
        {
            return 1;
        }
        if (this->y < position.getY())
        {
            return -1;
        }
        if (this->y > position.getY())
        {
            return 1;
        }
        return 0;
    }
}