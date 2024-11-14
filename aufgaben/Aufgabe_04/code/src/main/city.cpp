#include "city.h"

namespace oopTutorium
{
    std::string *City::makeSightsArray(const std::string sights[], int sightsLength)
    {
        std::string *storedSights = new std::string[sightsLength];
        for (int sight = 0; sight < sightsLength; sight++)
        {
            storedSights[sight] = sights[sight];
        }
        return storedSights;
    }

    City::City(const Position &position, const std::string *sights, int sightsLength) : position(position), sights(makeSightsArray(sights, sightsLength)), size(sightsLength)
    {
    }

    const std::string &City::getName() const
    {
        return position.getName();
    }

    int City::getX() const{
        return position.getX();
    }

    int City::getY() const{
        return position.getY();
    }
    
    const std::string &City::getPOI(int i) const{
        //a separate method should be written here to avoid redundancy
        if(i< 0 || i >= size){
            throw std::invalid_argument("index out of array range");
        }
        return sights[i];
    }

    void City::setPOI(int i, const std::string &name){
        //a separate method should be written here to avoid redundancy
        if(i< 0 || i >= size){
            throw std::invalid_argument("index out of array range");
        }
        sights[i] = name;
    }
    int City::getNumberOfPOIs(){
        return size;
    }
}
