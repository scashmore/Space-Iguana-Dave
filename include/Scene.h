#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

class Scene {
public:
    Scene(const std::string& description, const std::vector<std::string>& choices);
    const std::string& getDescription() const;
    const std::vector<std::string>& getChoices() const;
    void showScene() const;
    void makeChoice(int choiceIndex);
    void addOutcome(Scene* outcome); // Adds a connected scene
    int getNumChoices() const;
    Scene* getOutcome(int index) const;

private:
    std::string description;
    std::vector<std::string> choices;
    std::vector<Scene*> outcomes; // Connections to next scenes
};

#endif