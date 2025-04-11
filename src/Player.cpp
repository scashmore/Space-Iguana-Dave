#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : name(name), health(100), energy(100), coolness(1000),
      weapon("Banana Blaster", 15) {}

void Player::showStatus() const {
    std::cout << name << "'s Status:\n";
    std::cout << " - Health: " << health << "\n";
    std::cout << " - Energy: " << energy << "\n";
    std::cout << " - Coolness: " << coolness << "\n";
    std::cout << " - Weapon: " << weapon.getName() << " (Damage: " << weapon.getDamage() << ")\n";
}

void Player::addSkill(const std::string& skill) {
    skills.push_back(skill);
}

void Player::showSkills() const {
    std::cout << "Skills: ";
    for (const auto& skill : skills) {
        std::cout << skill << ", ";
    }
    std::cout << "\n";
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

Weapon Player::getWeapon() const {
    return weapon;
}

int Player::getHealth() const { return health; }
int Player::getEnergy() const { return energy; }
int Player::getCoolness() const { return coolness; }

void Player::addItem(const Item& item) {
    inventory.push_back(item);
    std::cout << "🎒 You picked up: " << item.getName() << "\n";
}

void Player::showInventory() const {
    std::cout << "\n📦 Inventory:\n";
    if (inventory.empty()) {
        std::cout << " (empty)\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i + 1 << ". " << inventory[i].getName() << "\n";
    }
}

void Player::useItem(int index) {
    if (index < 0 || index >= (int)inventory.size()) {
        std::cout << "❌ Invalid item index.\n";
        return;
    }

    Item item = inventory[index];
    switch (item.getType()) {
        case ItemType::Healing:
            health += item.getEffectValue();
            std::cout << "❤️ Restored " << item.getEffectValue() << " health!\n";
            break;
        case ItemType::Energy:
            energy += item.getEffectValue();
            std::cout << "⚡ Restored " << item.getEffectValue() << " energy!\n";
            break;
        case ItemType::Weapon:
            weapon = Weapon(item.getName(), item.getEffectValue());
            std::cout << "🗡️ Equipped new weapon: " << weapon.getName() << "!\n";
            break;
        case ItemType::Key:
            std::cout << "🔑 You used a key item: " << item.getName() << "\n";
            break;
        case ItemType::Misc:
            std::cout << "📦 You looked at: " << item.getName() << ". It’s probably junk... or is it?\n";
            break;
    }

    // Remove the used item if it's not a key or misc
    if (item.getType() != ItemType::Key && item.getType() != ItemType::Misc) {
        inventory.erase(inventory.begin() + index);
    }
}
