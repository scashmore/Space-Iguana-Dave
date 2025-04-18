#pragma once

#include "Story.h"

class Game {
public:
    Game(Story* story);
    void play();

private:
    Story* story;
    int getChoiceFromPlayer(int numChoices);
};
