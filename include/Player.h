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
    
    // New methods for the battle system
    bool hasWeapon(const std::string& weaponName) const;
    bool hasAbility(const std::string& abilityName) const;
    bool hasItem(const std::string& itemName) const;
    int getAgility() const;

    // Getters for player stats
    int getHealth() const;
    int getEnergy() const;
    int getCoolness() const;

private:
    std::string name;
    int health;
    int energy;
    int coolness;
    Weapon weapon;

    std::vector<std::string> skills; // List of skills (like "Shield")
    std::vector<Item> inventory;     // Inventory items
    int agility;                     // Player's agility stat (you can modify this value)
};
