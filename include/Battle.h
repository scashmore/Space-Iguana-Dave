#pragma once

#include "Player.h"
#include "Enemy.h"
#include "BattleAction.h"

class Battle {
public:
    Battle(Player& player, Enemy& enemy);
    void start();

private:
    Player& player;
    Enemy enemy;

    void playerTurn();
    void enemyTurn();
    void handleAction(const BattleAction& action);

    bool attemptEscape();
    void displayBattleStatus();
};