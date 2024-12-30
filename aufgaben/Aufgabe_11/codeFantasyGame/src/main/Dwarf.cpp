#include "Dwarf.hpp"

namespace oopTutorium
{
    Dwarf::Dwarf(const std::string name, int health, int axeWeight) : Character(name, health), axeWeight(axeWeight)
    {
    }

    void Dwarf::applyWeapon(Character &character)
    {
        if (&character != this && isAlife())
        {
            character.hit();
            character.hit();
            character.hit();
        }
    }

    int oopTutorium::Dwarf::getAxeWeight()
    {
        return axeWeight;
    }
}