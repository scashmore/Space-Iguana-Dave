#pragma once

#include "Scene.h"
#include <vector>
#include <unordered_map>
#include <string>

class Story {
public:
    Story();
    Scene* getCurrentScene() const;
    void goToScene(const std::string& id);
    void reset();

    void displayCurrentScene() const;
    Scene* getNextScene(int choiceIndex);

private:
    std::unordered_map<std::string, Scene*> scenes;
    std::string currentSceneId;

    void createStory(); // Internal function to populate scenes
};
