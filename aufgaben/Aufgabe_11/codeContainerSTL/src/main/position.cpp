#include "position.hpp"

namespace oopTutorium
{
    int Position::compare(const Position &position) const
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

    bool Position::operator==(const Position &other) const
    {
        return (compare(other) == 0);
    }
    bool Position::operator!=(const Position &other) const
    {
        return !(*this == other);
    }
    bool Position::operator<(const Position &other) const
    {
        return (compare(other) < 0);
    }
    bool Position::operator>(const Position &other) const
    {
        return (compare(other) > 0);
    }
    bool Position::operator<=(const Position &other) const
    {
        return !(*this > other);
    }
    bool Position::operator>=(const Position &other) const
    {
        return !(*this < other);;
    }
    std::ostream &operator<<(std::ostream &out, const Position &p)
    {
        out << "Name: " << p.getName() << ", x = " << p.getX() << ", y = " << p.getY();
        return out;
    }

    void sort(std::vector<Position> &positions)
    {
        std::map<Position,int> sortedPositions;
        for(Position pos : positions){
            sortedPositions[pos] = 0;
        }
        positions.clear();
        for(auto pos : sortedPositions){
            positions.push_back(pos.first);
        }
    }
}