#pragma once
#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health, int damage);

    std::string getName() const;
    int getHealth() const;
    int getDamage() const;

    void takeDamage(int amount);

private:
    std::string name;
    int health;
    int damage;
};
