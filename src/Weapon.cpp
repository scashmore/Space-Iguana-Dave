#include "Weapon.h"

Weapon::Weapon() : id(""), name(""), description(""), damage(0), type("") {}

Weapon::Weapon(const std::string& id, const std::string& name, const std::string& description, int damage, const std::string& type)
    : id(id), name(name), description(description), damage(damage), type(type) {}

Weapon::Weapon(const std::string& name, int damage)
    : name(name), damage(damage) {}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}
