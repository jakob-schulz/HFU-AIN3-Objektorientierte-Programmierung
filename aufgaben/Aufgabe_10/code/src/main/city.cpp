#include "city.h"

namespace oopTutorium
{
    vectorStrings City::makePoisArray(const std::string *pois, int poisLength)
    {
        if (pois == nullptr && poisLength != 0)
        {
            throw std::invalid_argument("an array length is passed but no array");
        }
        vectorStrings storedPois;
        for (int sight = 0; sight < poisLength; sight++)
        {
            storedPois.push_back(pois[sight]);
        }
        return storedPois;
    }

    int City::numberOfSamePois(const std::string &namePOI) const
    {
        int result = 0;
        for (unsigned int poi = 0; poi < pois.size(); poi++)
        {
            if (pois[poi] == namePOI)
            {
                result++;
            }
        }
        return result;
    }

    City::City(const Position &position, const std::string *pois, int poisLength) : position(position), pois(makePoisArray(pois, poisLength))
    {
    }

    City::City(const std::string &name, int x, int y, std::string *pois, int length) : City(Position(name, x, y), pois, length)
    {
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
        return pois.at(i); //at- Method checks whether n is within the bounds of valid elements in vector
    }

    void City::setPOI(int i, const std::string &name)
    {
        pois.at(i) = name;
    }

    int City::getNumberOfPOIs()
    {
        return pois.size();
    }

    void City::add(const std::string &namePOI)
    {
        pois.push_back(namePOI);
    }

    bool City::remove(const std::string &namePOI)
    {
        bool isRemoved = false;
        for(unsigned int poi = 0; poi < pois.size(); poi++){
            if(pois[poi] == namePOI)
            {
                pois.erase(pois.begin() + poi);
                poi--;
                isRemoved = true;
            }
        }
        return isRemoved;
    }

    std::string &City::operator[](int index)
    {
        return pois.at(index);
    }

    const std::string &City::operator[](int index) const
    {
        return getPOI(index);
    }

    std::ostream &operator<<(std::ostream &out, const City &p)
    {
        out << p.position << "\n";
        for(unsigned int poi = 0; poi < p.pois.size()-1; poi++){ //until -1 in order to avoid /n for the last element int the array
            out << p[poi];
            out << "\n";
        }
        out << p[p.pois.size()-1];
        return out;
    }
}
