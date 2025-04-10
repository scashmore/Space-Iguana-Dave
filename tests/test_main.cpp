#include "../include/Player.h"
#include "../include/Weapon.h"
#include <iostream>
#include <cassert>

void testPlayerDefaults() {
    Player dave("Dave");

    assert(dave.getHealth() == 100);
    assert(dave.getEnergy() == 100);
    assert(dave.getCoolness() == 1000);

    std::cout << "✅ Player default stats test passed.\n";
}

void testWeaponStats() {
    Weapon w("Banana Blaster", 15);
    assert(w.getName() == "Banana Blaster");
    assert(w.getDamage() == 15);
    std::cout << "✅ Weapon test passed.\n";
}

int main() {
    testPlayerDefaults();
    testWeaponStats();
    return 0;
}
