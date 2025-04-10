#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime> 

void showIntro() {
    std::cout << "🦎 Welcome to Space Iguana Dave! 🪐\n";
    std::cout << "You are Dave, a cosmic iguana with a destiny.\n";
    std::cout << "Type 'help' to see available commands.\n\n";
}

void showHelp() {
    std::cout << "Available commands:\n";
    std::cout << " - help: Show this help message\n";
    std::cout << " - status: Show Dave's current status\n";
    std::cout << " - quit: Exit the game\n";
}

void fight(Player& player) {
    std::srand(std::time(nullptr));
    Enemy enemy("Void Pigeon", 50, 10);

    std::cout << "\n👾 A wild " << enemy.getName() << " appears!\n";

    while (enemy.getHealth() > 0 && player.getHealth() > 0) {
        std::cout << "You blast the " << enemy.getName() << " for "
                  << player.getWeapon().getDamage() << " damage!\n";
        enemy.takeDamage(player.getWeapon().getDamage());

        if (enemy.getHealth() <= 0) {
            std::cout << "💥 You defeated the " << enemy.getName() << "!\n";
            break;
        }

        std::cout << "The " << enemy.getName() << " hits you for "
                  << enemy.getDamage() << " damage!\n";
        player.takeDamage(enemy.getDamage());

        if (player.getHealth() <= 0) {
            std::cout << "☠️ You were defeated by the " << enemy.getName() << "...\n";
            break;
        }
    }
}

int main() {
    showIntro();

    Player dave("Dave");

    std::string command;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, command);

        if (command == "help") {
            showHelp();
        } else if (command == "status") {
            dave.showStatus();
        } else if (command == "fight") {
            fight(dave);
        } else if (command == "quit") {
            std::cout << "Goodbye, brave iguana.\n";
            break;
        } else {
            std::cout << "Unknown command. Type 'help' to see options.\n";
        }
    }

    return 0;
}
