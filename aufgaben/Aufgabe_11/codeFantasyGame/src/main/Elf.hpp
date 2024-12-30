#include"Character.hpp"

namespace oopTutorium
{
    class Elf : public Character
    {
    private:
        int numberOfArrows;
    public:
        Elf(const std::string &name, int health, int numberOfArrows);
        virtual void applyWeapon(Character &character);
        int getArrows();
    };
    
}
