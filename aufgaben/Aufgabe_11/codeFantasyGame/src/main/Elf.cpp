#include "Elf.hpp"

oopTutorium::Elf::Elf(const std::string &name, int health, int numberOfArrows) : Character(name, health), numberOfArrows(numberOfArrows)
{
}

void oopTutorium::Elf::applyWeapon(Character &character)
{
    if (&character != this && isAlife() && numberOfArrows > 0)
    {
        numberOfArrows--;
        character.hit();
        character.hit();
    }
}

int oopTutorium::Elf::getArrows()
{
    return numberOfArrows;
}