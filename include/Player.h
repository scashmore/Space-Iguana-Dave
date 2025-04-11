#pragma once

#include "Weapon.h"
#include "Item.h"
#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name);

    void showStatus() const;
    void showSkills() const;
    void showInventory() const;

    void addSkill(const std::string& skill);
    void takeDamage(int amount);

    void addItem(const Item& item);
    void useItem(int index);

    Weapon getWeapon() const;

    int getHealth() const;
    int getEnergy() const;
    int getCoolness() const;

private:
    std::string name;
    int health;
    int energy;
    int coolness;
    Weapon weapon;

    std::vector<std::string> skills;
    std::vector<Item> inventory;
};