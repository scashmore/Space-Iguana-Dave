#pragma once

#include <string>

class Weapon {
public:
    Weapon();  // Default constructor
    Weapon(const std::string& id, const std::string& name, const std::string& description, int damage, const std::string& type);
    Weapon(const std::string& name, int damage);

    std::string getName() const;
    int getDamage() const;

private:
    std::string id;
    std::string name;
    std::string description;
    int damage;
    std::string type;
};
