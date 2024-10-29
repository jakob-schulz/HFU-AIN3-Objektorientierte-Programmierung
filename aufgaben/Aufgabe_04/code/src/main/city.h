#include"position.hpp"

namespace oopTutorium
{
    class City
    {
    private:
        Position position;
        std::string *sights;
        int size;
    public:
        City(const Position& position, const std::string *sights, int sightsLength);
        const std::string& getName() const;
        int getX() const;
        int getY() const;
        const Position& getPoint();
        const std::string& getPOI(int i) const;
        void setPOI(int i, const std::string& name);
        int getNumberOfPOIs();
    };
}
