#include "../include/Player.h"
#include <iostream>
#include <cassert>

void testPlayerDefaults() {
    Player dave("Dave");

    assert(dave.getHealth() == 100);
    assert(dave.getEnergy() == 100);
    assert(dave.getCoolness() == 1000);

    std::cout << "✅ Player default stats test passed.\n";
}

int main() {
    testPlayerDefaults();
    return 0;
}
