#include"position.hpp"

namespace oopTutorium
{
    class City
    {
    private:
        Position position;
        std::string *pois;
        int size;
        static std::string *makePoisArray(const std::string *pois, int poisLength);
        City(const Position& position, const std::string *pois, int poisLength);
        void checkIndexOutOfBounds(int i) const;
    public:
        City(const std::string &name, int x, int y, std::string *pois, int length);
        City(const City &city); //copy constructor is needed because the class city has an array of points of interest which must be copied
        ~City(); //destructor is needed because the array of points of interest must be deleted
        const std::string& getName() const;
        int getX() const;
        int getY() const;
        const std::string& getPOI(int i) const;
        void setPOI(int i, const std::string& name);
        int getNumberOfPOIs();
    };
}
