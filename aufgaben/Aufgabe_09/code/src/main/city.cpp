#include "city.h"

namespace oopTutorium
{
    std::unique_ptr<std::string[]> City::makePoisArray(const std::string *pois, int poisLength)
    {
        if (pois == nullptr && poisLength != 0)
        {
            throw std::invalid_argument("an array length is passed but no array");
        }
        std::unique_ptr<std::string[]> storedPois = std::make_unique<std::string[]>(poisLength);
        for (int sight = 0; sight < poisLength; sight++)
        {
            storedPois[sight] = pois[sight];
        }
        return storedPois;
    }

    void City::checkIndexOutOfBounds(int i) const
    {
        if (i < 0 || i >= size)
        {
            throw std::invalid_argument("index out of array bounds");
        }
    }

    int City::numberOfSamePois(const std::string &namePOI) const
    {
        int result = 0;
        for (int poi = 0; poi < size; poi++)
        {
            if (pois[poi] == namePOI)
            {
                result++;
            }
        }
        return result;
    }

    City::City(const Position &position, const std::string *pois, int poisLength) : position(position), pois(makePoisArray(pois, poisLength)), size(poisLength)
    {
    }

    City::City(const std::string &name, int x, int y, std::string *pois, int length) : City(Position(name, x, y), pois, length)
    {
    }

    City::City(const City &city) : City(city.position, city.pois.get(), city.size) //get-Method: returns a pointer to the managed object
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

    void City::add(const std::string &namePOI)
    {
        std::string *updatedPois = new std::string[size + 1];
        for (int poi = 0; poi < size; poi++)
        {
            updatedPois[poi] = pois[poi];
        }
        updatedPois[size] = namePOI;
        size = size + 1;
        pois.reset(updatedPois); //replaces the old unique_ptr with a new one
    }

    bool City::remove(const std::string &namePOI)
    {
        int numberOfPoisToRemove = numberOfSamePois(namePOI);
        if (numberOfPoisToRemove > 0)
        {
            size = size - numberOfPoisToRemove;
            std::string *updatedPois = new std::string[size];
            int poi = 0;
            for (int updatedPoi = 0; updatedPoi < size; updatedPoi++)
            {
                if (pois[poi] == namePOI)
                {
                    poi++;
                    if (updatedPoi >= size)
                    {
                        break;
                    }
                }
                updatedPois[updatedPoi] = pois[poi];
                poi++;
            }
            pois.reset(updatedPois); //replaces the old unique_ptr with a new one
            return true;
        }
        return false;
    }

    std::string &City::operator[](int index)
    {
        this->checkIndexOutOfBounds(index);
        return pois[index];
    }

    const std::string &City::operator[](int index) const
    {
        return getPOI(index);
    }

    City &City::operator=(const City &other)
    {
        if(this == &other)
        {
            return *this;
        }
        this->position = other.position;
        this->size = other.size;
        std::unique_ptr<std::string[]> newPois = makePoisArray(other.pois.get(), other.size); //get-Method: returns a pointer to the managed object
        pois.reset(newPois.release());
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const City &p)
    {
        out << p.position << "\n";
        for(int poi = 0; poi < p.size-1; poi++){ //until -1 in order to avoid /n for the last element int the array
            out << p[poi];
            out << "\n";
        }
        out << p[p.size-1];
        return out;
    }
}
