#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : name(name), health(100), energy(100), coolness(1000) {}

void Player::showStatus() const {
    std::cout << name << "'s Status:\n";
    std::cout << " - Health: " << health << "\n";
    std::cout << " - Energy: " << energy << "\n";
    std::cout << " - Coolness: " << coolness << "\n";
}

int Player::getHealth() const { return health; }
int Player::getEnergy() const { return energy; }
int Player::getCoolness() const { return coolness; }
