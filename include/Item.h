#pragma once
#include <string>

enum class ItemType {
    Healing,
    Energy,
    Weapon,
    Key,
    Misc
};

class Item {
public:
    Item(const std::string& name, ItemType type, int effectValue = 0);

    std::string getName() const;
    ItemType getType() const;
    int getEffectValue() const;

private:
    std::string name;
    ItemType type;
    int effectValue; // How much it heals, restores, etc.
};