#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include <string>

class Player {
    public:
        Player(const std::string& name);

        void showStatus() const;

        // Getters for testing
        int getHealth() const;
        int getEnergy() const;
        int getCoolness() const;
    private:
        std::string name;
        int health;
        int energy;
        int coolness;
        Weapon weapon;
};

#endif