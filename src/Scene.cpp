#include "Scene.h"
#include <iostream>

Scene::Scene(const std::string& description, const std::vector<std::string>& choices)
    : description(description), choices(choices) {}

void Scene::showScene() const {
    std::cout << description << "\n";
    for (int i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }
}

void Scene::makeChoice(int choiceIndex) {
    // Implement how each choice leads to an outcome (new scene)
    if (choiceIndex >= 0 && choiceIndex < outcomes.size()) {
        outcomes[choiceIndex]->showScene();
    }
}

void Scene::addOutcome(Scene* outcome) {
    outcomes.push_back(outcome);
}

int Scene::getNumChoices() const {
    return choices.size();
}

Scene* Scene::getOutcome(int index) const {
    if (index >= 0 && index < outcomes.size()) {
        return outcomes[index];
    }
    return nullptr;
}