#include "Game.h"
#include <iostream>

Game::Game(Story* story) : story(story) {}

void Game::play() {
    while (true) {
        story->displayCurrentScene();

        Scene* current = story->getCurrentScene();
        int numChoices = current->getNumChoices();
        if (numChoices == 0) {
            std::cout << "🎉 The story has ended. Thanks for playing!\n";
            break;
        }

        int choice = getChoiceFromPlayer(numChoices);
        Scene* next = story->getNextScene(choice);
        if (!next) {
            std::cout << "❌ Invalid choice. Try again.\n";
        }
    }
}

int Game::getChoiceFromPlayer(int numChoices) {
    int choice = -1;
    while (true) {
        std::cout << "➡️ Enter your choice (1-" << numChoices << "): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "quit" || input == "exit") {
            std::cout << "👋 Goodbye!\n";
            exit(0);
        }

        try {
            choice = std::stoi(input);
            if (choice >= 1 && choice <= numChoices) {
                return choice - 1;
            }
        } catch (...) {}

        std::cout << "❌ Invalid input. Please enter a number between 1 and " << numChoices << ".\n";
    }
}