#include "Story.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Story::Story() {
    createStory();
}

void Story::createStory() {
    std::ifstream file("data/story.json");
    if (!file.is_open()) {
        std::cerr << "❌ Failed to open story.json\n";
        return;
    }

    json storyData;
    file >> storyData;

    // First pass: create scenes
    for (auto& [id, node] : storyData.items()) {
        std::string description = node["description"];
        std::vector<std::string> choices;

        for (const auto& choice : node["choices"]) {
            choices.push_back(choice["text"]);
        }

        scenes[id] = new Scene(description, choices);
    }

    // Second pass: wire outcomes
    for (auto& [id, node] : storyData.items()) {
        Scene* scene = scenes[id];

        for (const auto& choice : node["choices"]) {
            std::string nextId = choice["next"];
            if (scenes.count(nextId)) {
                scene->addOutcome(scenes[nextId]);
            } else {
                std::cerr << "⚠️  Invalid next scene ID: " << nextId << " in scene " << id << "\n";
            }
        }
    }

    currentSceneId = "start";
}

Scene* Story::getCurrentScene() const {
    return scenes.at(currentSceneId);
}

Scene* Story::getNextScene(int choiceIndex) {
    Scene* current = getCurrentScene();
    Scene* next = current->getOutcome(choiceIndex);
    if (next) {
        for (auto& [id, scene] : scenes) {
            if (scene == next) {
                currentSceneId = id;
                return next;
            }
        }
    }
    return nullptr;
}

void Story::goToScene(const std::string& id) {
    if (scenes.count(id)) {
        currentSceneId = id;
    }
}

void Story::reset() {
    currentSceneId = "start";
}

void Story::displayCurrentScene() const {
    scenes.at(currentSceneId)->showScene();
}
