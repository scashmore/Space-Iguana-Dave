#pragma once
#include "Enemy.h"

class Boss : public Enemy {
public:
    Boss(const std::string& name, int health, int attack, int defense, int agility, Weapon weapon, int specialAbilityPower);
    
    int getSpecialAbilityPower() const;
    void useSpecialAbility(Enemy& target);

private:
    int specialAbilityPower;
};