#include <iostream>
#include <vector>
#include "../main/Character.hpp"
#include "../main/Dwarf.hpp"
#include "../main/Elf.hpp"
#include "../main/Orc.hpp"

namespace oopTutorium
{
    void testFight()
    {
        Dwarf bob("Bob", 5, 40);
        Dwarf alice("Alice", 5, 40);
        Elf eve("Eve", 8, 7);
        Orc mallory("Mallory", 10, 150);
        std::vector<Character *> fight = {&bob, &alice, &eve, &mallory};

        fight[2]->applyWeapon(*fight[3]);
        fight[3]->applyWeapon(*fight[1]);
        fight[1]->applyWeapon(*fight[3]);
        fight[3]->applyWeapon(*fight[0]);
        fight[2]->applyWeapon(*fight[0]);
        fight[1]->applyWeapon(*fight[2]);
        fight[2]->applyWeapon(*fight[3]);
        fight[2]->applyWeapon(*fight[3]);
        fight[3]->applyWeapon(*fight[2]);
        fight[1]->applyWeapon(*fight[3]);
        fight[2]->applyWeapon(*fight[1]);
        fight[2]->applyWeapon(*fight[1]);
        fight[0]->applyWeapon(*fight[2]);
        fight[0]->applyWeapon(*fight[2]);

        for (Character *character : fight)
        {
            if (character->isAlife())
            {
                std::cout << character->getName() << std::endl;
            }
        }
    }

}

int main()
{
    std::cout << "starting..." << std::endl;
    oopTutorium::testFight();
    std::cout << "...terminating" << std::endl;
}
