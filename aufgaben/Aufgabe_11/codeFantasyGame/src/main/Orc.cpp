#include "Orc.hpp"

namespace oopTutorium
{
    Orc::Orc(const std::string &name, int health, int swordLength) : Character(name, health), swordLength(swordLength)
    {
    }

    void Orc::applyWeapon(Character &character)
    {
        if (&character != this && isAlife())
        {
            character.hit();
        }
    }

    int Orc::getSwordLength()
    {
        return swordLength;
    }
}