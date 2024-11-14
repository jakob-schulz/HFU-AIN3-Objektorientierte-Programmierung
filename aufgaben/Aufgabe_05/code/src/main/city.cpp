#include "city.h"

namespace oopTutorium
{
    std::string *City::makePoisArray(const std::string *pois, int poisLength)
    {
        std::string *storedPois = new std::string[poisLength];
        for (int sight = 0; sight < poisLength; sight++)
        {
            storedPois[sight] = pois[sight];
        }
        return storedPois;
    }

    City::City(const Position &position, const std::string *pois, int poisLength) : position(position), pois(makePoisArray(pois, poisLength)), size(poisLength)
    {
    }

    City::City(const std::string &name, int x, int y, std::string *pois, int length) : City(Position(name, x, y), pois, length)
    {
    }

    City::City(const City &city) : City(city.position, city.pois, city.size)
    {
    }

    City::~City()
    {
        delete[] pois;
        pois = nullptr;
    }

    void City::checkIndexOutOfBounds(int i) const{
        if (i < 0 || i >= size)
        {
            throw std::invalid_argument("index out of array bounds");
        }
    }

    const std::string &City::getName() const
    {
        return position.getName();
    }

    int City::getX() const
    {
        return position.getX();
    }

    int City::getY() const
    {
        return position.getY();
    }

    const std::string &City::getPOI(int i) const
    {
        this->checkIndexOutOfBounds(i);
        return pois[i];
    }

    void City::setPOI(int i, const std::string &name)
    {
        this->checkIndexOutOfBounds(i);
        pois[i] = name;
    }
    int City::getNumberOfPOIs()
    {
        return size;
    }
}
