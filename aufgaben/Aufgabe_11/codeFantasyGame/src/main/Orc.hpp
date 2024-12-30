#include"Character.hpp"

namespace oopTutorium
{
    class Orc : public Character
    {
    private:
        int swordLength;
    public:
        Orc(const std::string &name, int health, int swordLength);
        virtual void applyWeapon(Character &character);
        int getSwordLength();
    };
    
}