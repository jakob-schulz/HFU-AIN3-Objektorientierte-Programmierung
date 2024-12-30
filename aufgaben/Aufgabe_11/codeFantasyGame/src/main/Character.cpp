#include"Character.hpp"

namespace oopTutorium
{
    Character::Character(const std::string &name, int health) : name(name), health(health)
    {
    }

    const std::string &Character::getName() const
    {
        return name;
    }

    bool Character::isAlife() const
    {
        if (health <= 0)
        {
            return false;
        }
        return true;
    }

    void Character::hit()
    {
        health--;
    }
}