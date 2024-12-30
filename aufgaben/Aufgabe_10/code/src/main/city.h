#include "position.hpp"
#include<vector>

namespace oopTutorium
{
    typedef std::vector<std::string> vectorStrings;
    class City
    {
    private:
        Position position;
        vectorStrings pois;
        vectorStrings makePoisArray(const std::string *pois, int poisLength);
        City(const Position &position, const std::string *pois, int poisLength);
        int numberOfSamePois(const std::string &namePOI) const;
        const std::string &getPOI(int i) const;
        void setPOI(int i, const std::string &name);

    public:
        City(const std::string &name, int x, int y, std::string *pois = nullptr, int length = 0);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int getNumberOfPOIs();
        void add(const std::string &namePOI);
        bool remove(const std::string &namePOI);
        std::string &operator[](int index);
        const std::string &operator[](int index) const;
        friend std::ostream &operator<<(std::ostream &out, const City &p);
    };
}
