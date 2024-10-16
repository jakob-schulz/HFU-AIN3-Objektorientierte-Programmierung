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
        void set(const std::string &name, int x, int y);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
    };
}
