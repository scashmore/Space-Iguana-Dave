#include "Game.h"
#include "helpers/InputHelper.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

Game::Game(Story* story) : story(story) {}

void Game::play() {
    while (true) {
        story->displayCurrentScene();

        Scene* current = story->getCurrentScene();
        int numChoices = current->getNumChoices();

        if (numChoices == 0) {  // If it's an ending scene
            std::cout << "🎉 The story has ended. Thanks for playing!\n";
            std::cout << "Press enter to exit...\n";
            std::cin.get();  // Wait for a key press before exiting
            break;  // Exit the game loop
        }

        int choice = getChoiceFromPlayer(numChoices);

        // Determine the ID of the scene the choice points to
        std::string nextId = story->getCurrentSceneIdFromChoice(choice);

        // Check if the next scene is a battle trigger
        if (nextId == "seagullBattle") {
            runBattle("spaceSeagull");
            continue;  // Don't go to the scene directly; the battle handles it
        }

        Scene* next = story->getNextScene(choice);
        if (!next) {
            std::cout << "❌ Invalid choice. Try again.\n";
            continue;
        }

        story->goToScene(nextId);
    }
}

int Game::getChoiceFromPlayer(int numChoices) {
    while (true) {
        std::cout << "➡️ Enter your choice (1-" << numChoices << "): ";
        char input = getCharFromUser();

        // Quit option
        if (input == 'q' || input == 'Q') {
            std::cout << "👋 Goodbye!\n";
            exit(0);
        }

        // Check if input is a digit and within range
        if (isdigit(input)) {
            int choice = input - '0';
            if (choice >= 1 && choice <= numChoices) {
                return choice - 1; // return 0-based index
            }
        }

        std::cout << "❌ Invalid input. Please enter a number between 1 and " << numChoices << ".\n";
    }
}



void Game::runBattle(const std::string& enemyId) {
    // For now, hardcoded values for the Space Seagull
    int enemyHealth = 30;
    int playerHealth = 25;

    std::cout << "⚔️ Battle begins with the " << enemyId << "!\n";

    while (enemyHealth > 0 && playerHealth > 0) {
        std::cout << "\nYour HP: " << playerHealth << " | Enemy HP: " << enemyHealth << "\n";
        std::cout << "1. Attack\n2. Defend\n3. Run Away\n➡️ Choose an action: ";

        char input = getCharFromUser();

        if (input == '1') {
            std::cout << "🟡 You blast the enemy with your Banana Blaster!\n";
            enemyHealth -= 10;
        } else if (input == '2') {
            std::cout << "🛡️ You brace yourself for impact.\n";
            playerHealth -= 2; // Reduced damage
        } else if (input == '3') {
            std::cout << "🏃 You try to run... but the Space Seagull blocks your way!\n";
            playerHealth -= 5;
        } else {
            std::cout << "❌ Invalid input!\n";
            continue;
        }

        if (enemyHealth > 0) {
            std::cout << "💥 The enemy strikes back!\n";
            playerHealth -= 5;
        }
    }

    if (playerHealth <= 0) {
        std::cout << "\n☠️ You were defeated by the " << enemyId << "...\n";
        story->goToScene("youDied");  // Make sure this scene exists
    } else {
        std::cout << "\n🎉 You defeated the " << enemyId << "!\n";
        story->goToScene("spaceSeagull");  // Make sure this ID is in enemyDeaths.json
    }
}

