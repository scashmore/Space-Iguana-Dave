#pragma once

enum class ActionType {
    Attack,
    UseItem,
    Defend,
    RunAway
};

class BattleAction {
public:
    BattleAction(ActionType type, int choice = 0);

    ActionType getActionType() const;
    int getChoice() const;

private:
    ActionType type;
    int choice;
};
