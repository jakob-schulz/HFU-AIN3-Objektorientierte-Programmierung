#ifndef _POSITION_

#define  _POSITION_
#include <iostream>

namespace oopTutorium
{
    class Position
    {
    private:
        std::string name;
        int x;
        int y;
        int compare(const Position &position);

    public:
        Position(const std::string &name, int x, int y);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        bool operator==(const Position &other);
        bool operator!=(const Position &other);
        bool operator<(const Position &other);
        bool operator>(const Position &other);
        bool operator<=(const Position &other);
        bool operator>=(const Position &other);
    };
    std::ostream &operator<<(std::ostream &out, const Position &p);
}
#endif
