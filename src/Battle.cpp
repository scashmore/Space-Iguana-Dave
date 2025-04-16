#include "Battle.h"
#include <iostream>
#include <cstdlib> // for rand()

Battle::Battle(Player& player, Enemy& enemy)
    : player(player), enemy(enemy) {}

void Battle::start() {
    std::cout << "⚔️ A wild " << enemy.getName() << " appears!\n";

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        displayBattleStatus();
        playerTurn();

        if (enemy.getHealth() <= 0) {
            std::cout << "🎉 You defeated " << enemy.getName() << "!\n";
            break;
        }

        enemyTurn();

        if (player.getHealth() <= 0) {
            std::cout << "💀 You were defeated by " << enemy.getName() << ".\n";
            break;
        }
    }
}

void Battle::displayBattleStatus() {
    std::cout << "\n--- BATTLE STATUS ---\n";
    player.showStatus();
    std::cout << enemy.getName() << "'s Health: " << enemy.getHealth() << "\n";
}

void Battle::playerTurn() {
    std::cout << "\nYour turn! Choose an action:\n";
    
    // Example dynamic options
    std::vector<std::string> choices;
    
    // Add Attack options based on player's available weapons
    if (player.hasWeapon("Laser Gun")) {
        choices.push_back("Attack with Laser Gun");
    }
    
    // Add Defense options based on player's armor or abilities
    if (player.hasAbility("Shield")) {
        choices.push_back("Use Shield");
    }
    
    // Add Item usage options
    if (player.hasItem("Health Potion")) {
        choices.push_back("Use Health Potion");
    }
    
    // Add Escape option based on agility
    if (player.getAgility() > 10) {
        choices.push_back("Run Away");
    }

    // Show the dynamic choices
    for (size_t i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }
    
    std::cout << "➡️ Choose an option: ";
    int choiceIndex;
    std::cin >> choiceIndex;
    
    // Handle the player's choice (you could expand this with more options)
    switch (choiceIndex) {
        case 1: // Attack with Laser Gun
            // Implement attack logic
            break;
        case 2: // Use Shield
            // Implement shield logic
            break;
        case 3: // Use Health Potion
            // Implement health potion logic
            break;
        case 4: // Run Away
            // Implement escape logic
            break;
        default:
            std::cout << "❌ Invalid choice!\n";
    }
}


void Battle::enemyTurn() {
    int damage = enemy.getDamage(); // You’ll add logic for variety later
    player.takeDamage(damage);
    std::cout << "👾 " << enemy.getName() << " attacks you for " << damage << " damage!\n";
}

bool Battle::attemptEscape() {
    int roll = rand() % 100;
    return roll < 50; // 50% chance to escape
}
