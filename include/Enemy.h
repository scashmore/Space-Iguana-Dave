#pragma once
#include <string>

class Enemy {
public:
    // Default constructor
    Enemy() : name(""), health(0), damage(0) {}

    // Parameterized constructor
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
