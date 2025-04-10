#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

class Scene {
public:
    Scene(const std::string& description, const std::vector<std::string>& choices);
    void showScene() const;
    void makeChoice(int choiceIndex);

private:
    std::string description;
    std::vector<std::string> choices;
    std::vector<Scene*> outcomes; // Connections to next scenes
    void addOutcome(Scene* outcome); // Adds a connected scene
};

#endif