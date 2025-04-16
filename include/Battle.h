#pragma once

#include "Player.h"
#include "Enemy.h"
#include "BattleAction.h"
#include <functional>  // For std::function

class Battle {
public:
    Battle(Player& player, Enemy& enemy, std::function<void(bool)> onBattleComplete); // Correct constructor
    void start();  // This method runs the entire battle

private:
    Player& player;
    Enemy enemy;
    std::function<void(bool)> onBattleComplete;  // Callback to notify battle outcome

    void playerTurn();
    void enemyTurn();
    void handleAction(const BattleAction& action);

    bool attemptEscape();
    void displayBattleStatus();
};
