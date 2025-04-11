#include "Game.h"
#include "Story.h"
#include <iostream>

void showTitleScreen() {
    std::cout << R"(
   _.-~~-.__
 _-~ _-=-_   ''-,,
('___ ~~~   0     ~''-_,,,,,,,,,,,,,,,,
 \~~~~~~--'                            '''''''--,,,,
  ~`-,_      ()                                     '''',,,
       '-,_      \                           /             '', _~/|
  ,.       \||/~--\ \_________              / /______...---.  ;  /
  \ ~~~~~~~~~~~~~  \ )~~------~`~~~~~~~~~~~( /----         /,'/ /
   |   -           / /                      \ \           /;/  /
  / -             / /                        / \         /;/  / -.
 /         __.---/  \__                     /, /|       |:|    \  \
/_.~`-----~      \.  \ ~~~~~~~~~~~~~---~`---\\\\ \---__ \:\    /  /
                  `\\\`                     ' \\' '    --\'\, /  /
                                               '\,        ~-_'''"
                    🦎  Space Iguana Dave  🦎
    )" << "\n";
    std::cout << "1. Play the Story\n";
    std::cout << "2. Test Fight (Coming Soon)\n";
    std::cout << "3. Quit\n";
}

int main() {
    while (true) {
        showTitleScreen();

        std::cout << "\n➡️ Select an option: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "1") {
            Story story;
            Game game(&story);
            game.play();
        } else if (input == "2") {
            std::cout << "\n🛠️  Fight system is still under construction!\n\n";
        } else if (input == "3" || input == "quit" || input == "exit") {
            std::cout << "👋 Thanks for playing Space Iguana Dave!\n";
            break;
        } else {
            std::cout << "❌ Invalid input. Please try again.\n\n";
        }
    }

    return 0;
}
