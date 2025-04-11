#include "InputHelper.h"
#include <termios.h>
#include <unistd.h>

char getCharFromUser() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);          // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    read(STDIN_FILENO, &ch, 1);              // Read one character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch;
}
