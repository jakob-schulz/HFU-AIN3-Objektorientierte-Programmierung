#include "position.hpp"

namespace oopTutorium
{
    class City
    {
    private:
        Position position;
        std::string *pois;
        int size;
        static std::string *makePoisArray(const std::string *pois, int poisLength);
        City(const Position &position, const std::string *pois, int poisLength);
        void checkIndexOutOfBounds(int i) const;
        int numberOfSamePois(const std::string &namePOI) const;
        const std::string &getPOI(int i) const;
        void setPOI(int i, const std::string &name);

    public:
        City(const std::string &name, int x, int y, std::string *pois = nullptr, int length = 0);
        City(const City &city);
        ~City();
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int getNumberOfPOIs();
        void add(const std::string &namePOI);
        bool remove(const std::string &namePOI);
        std::string &operator[](int index); //the reference is required to avoid copies and to be able to assign new values to the array at a position
        const std::string &operator[](int index) const;
        City &operator=(const City &other);
        friend std::ostream &operator<<(std::ostream &out, const City &p);
    };
}
