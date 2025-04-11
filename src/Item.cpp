#include "Item.h"

Item::Item(const std::string& name, ItemType type, int effectValue)
    : name(name), type(type), effectValue(effectValue) {}

std::string Item::getName() const {
    return name;
}

ItemType Item::getType() const {
    return type;
}

int Item::getEffectValue() const {
    return effectValue;
}