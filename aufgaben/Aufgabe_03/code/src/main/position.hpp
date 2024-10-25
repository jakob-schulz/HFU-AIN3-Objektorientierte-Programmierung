#include <iostream>

namespace oopTutorium
{
    class Position
    {
    private:
        std::string name;
        int x;
        int y;

    public:
        Position(const std::string &name, int x, int y);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int compare(const Position &position);
    };
}
