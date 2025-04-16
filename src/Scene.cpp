#include "Scene.h"
#include <iostream>

Scene::Scene(const std::string& description, const std::vector<Choice>& choices)
    : description(description), choices(choices), type("choice"), enemyId(std::nullopt), nextSceneId(std::nullopt) {}

const std::string& Scene::getDescription() const {
    return description;
}

const std::vector<Choice>& Scene::getChoices() const {
    return choices;
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

void Scene::showScene() const {
    std::cout << description << "\n";
    for (int i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i].text << "\n";
    }
}

void Scene::makeChoice(int choiceIndex) {
    if (choiceIndex >= 0 && choiceIndex < outcomes.size()) {
        outcomes[choiceIndex]->showScene();
    }
}

void Scene::addOutcome(Scene* outcome) {
    outcomes.push_back(outcome);
}

// Battle-related methods
std::string Scene::getType() const {
    return type;
}

bool Scene::hasEnemy() const {
    return enemyId.has_value();
}

std::string Scene::getEnemyId() const {
    if (enemyId) {
        return enemyId.value();
    }
    return "";  // Empty string if there's no enemy
}

bool Scene::hasNextScene() const {
    return nextSceneId.has_value();
}

std::string Scene::getNextScene() const {
    if (nextSceneId) {
        return nextSceneId.value();
    }
    return "";  // Return an empty string if there's no next scene
}

void Scene::setType(const std::string& sceneType) {
    type = sceneType;
}

void Scene::setEnemyId(const std::string& id) {
    enemyId = id;
}

void Scene::setNextSceneId(const std::string& nextScene) {
    nextSceneId = nextScene;
}
