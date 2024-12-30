#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

namespace oopTutorium
{
    class Character
    {
    private:
        std::string name;
        int health;

    public:
        Character(const std::string &name, int health);
        const std::string &getName() const;
        bool isAlife() const;
        void hit();
        virtual void applyWeapon(Character &character) = 0;
    };
}

#endif