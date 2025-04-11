#include "Game.h"
#include "helpers/InputHelper.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Function to get a single character from the user without pressing enter
char getCharFromUser() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch;
}

Game::Game(Story* story) : story(story) {}

void Game::play() {
    while (true) {
        story->displayCurrentScene();

        Scene* current = story->getCurrentScene();
        int numChoices = current->getNumChoices();
        
        if (numChoices == 0) { // If it's an ending scene
            std::cout << "🎉 The story has ended. Thanks for playing!\n";
            std::cout << "Press enter to exit...\n";
            std::cin.get();  // Wait for a key press before exiting
            break;  // Exit the game loop
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
        
        // Get the user input without pressing Enter
        char input = getCharFromUser();

        // Handle quit options
        if (input == 'q' || input == 'Q') {
            std::cout << "👋 Goodbye!\n";
            exit(0);
        }

        // Check if the input is a valid choice
        if (input >= '1' && input <= '0' + numChoices) {
            choice = input - '1';
            return choice;
        }

        std::cout << "❌ Invalid input. Please enter a number between 1 and " << numChoices << ".\n";
    }
}
