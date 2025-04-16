#pragma once

#include "Story.h"

class Game {
public:
    Game(Story* story);
    void play();
    void runBattle(const std::string& enemyId);

private:
    Story* story;
    int getChoiceFromPlayer(int numChoices);
};
