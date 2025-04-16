#pragma once
#include <string>
#include "Weapon.h"
#include "Item.h"

class Enemy {
public:
    Enemy(const std::string& name, int health, int attack, int defense, int agility, Weapon weapon);
    
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getAgility() const;
    Weapon getWeapon() const;
    
    void takeDamage(int damage);
    bool isAlive() const;

private:
    std::string name;
    int health;
    int attack;
    int defense;
    int agility;
    Weapon weapon;
};