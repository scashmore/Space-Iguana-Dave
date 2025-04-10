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
