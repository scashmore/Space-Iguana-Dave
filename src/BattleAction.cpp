#include "BattleAction.h"

BattleAction::BattleAction(ActionType type, int choice)
    : type(type), choice(choice) {}

ActionType BattleAction::getActionType() const {
    return type;
}

int BattleAction::getChoice() const {
    return choice;
}