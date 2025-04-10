#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Story.h"
#include <cstdlib>
#include <ctime> 
#include <limits>


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

void playStory(Player& player) {
    std::vector<Scene*> story = createStory();
    Scene* current = story[0];

    while (current) {
        current->showScene();

        std::cout << "\nChoose an option (1-" << current->getNumChoices() << ", or 0 to exit story): ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            std::cout << "🚫 Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "📖 Dave drifts into the void of storylessness...\n";
            break;
        }

        Scene* next = current->getOutcome(choice - 1);
        if (next) {
            current = next;
        } else {
            std::cout << "🚫 Invalid choice! Try again.\n";
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
        }else if (command == "play") {
            playStory(dave);
        } else if (command == "quit") {
            std::cout << "Goodbye, brave iguana.\n";
            break;
        } else {
            std::cout << "Unknown command. Type 'help' to see options.\n";
        }
    }

    return 0;
}
