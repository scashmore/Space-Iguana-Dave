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
    std::cout << "1. Attack\n";
    std::cout << "2. Use Item (coming soon)\n";
    std::cout << "3. Defend (coming soon)\n";
    std::cout << "4. Run Away\n";
    std::cout << "➡️ ";

    std::string input;
    std::getline(std::cin, input);

    if (input == "1") {
        int damage = player.getWeapon().getDamage();  // we'll later improve this with battle moves
        enemy.takeDamage(damage);
        std::cout << "💥 You attacked " << enemy.getName() << " for " << damage << " damage!\n";
    } else if (input == "4") {
        if (attemptEscape()) {
            std::cout << "🏃 You escaped successfully!\n";
            exit(0); // For now, just end the game if you escape
        } else {
            std::cout << "🚫 Escape failed!\n";
        }
    } else {
        std::cout << "❌ Not implemented yet or invalid choice!\n";
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
