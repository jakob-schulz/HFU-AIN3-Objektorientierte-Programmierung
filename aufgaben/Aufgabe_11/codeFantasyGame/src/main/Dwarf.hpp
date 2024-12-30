#include"Character.hpp"

namespace oopTutorium
{
    class Dwarf : public Character
    {
    private:
        int axeWeight;
    public:
        Dwarf(const std::string name, int health, int axeWeight);
        virtual void applyWeapon(Character &character) override;
        int getAxeWeight();
    };

}
