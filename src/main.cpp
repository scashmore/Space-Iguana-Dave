#include <iostream>
#include <string>
#include "Player.h"

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
        } else if (command == "quit") {
            std::cout << "Goodbye, brave iguana.\n";
            break;
        } else {
            std::cout << "Unknown command. Type 'help' to see options.\n";
        }
    }

    return 0;
}
