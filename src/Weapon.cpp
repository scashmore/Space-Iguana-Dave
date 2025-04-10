#include "Weapon.h"

Weapon::Weapon(const std::string& name, int damage)
    : name(name), damage(damage) {}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}