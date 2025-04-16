#pragma once

#include <string>
#include <vector>
#include <optional>

class Enemy;  // Forward declaration of Enemy class

// Structure representing a choice in the scene
struct Choice {
    std::string text;   // The text shown for the choice
    std::string next;   // The ID of the next scene when the choice is made
};

class Scene {
public:
    // Constructor
    Scene(const std::string& description, const std::vector<Choice>& choices);

    // Getter methods
    const std::string& getDescription() const;                    // Get the scene's description
    const std::vector<Choice>& getChoices() const;                 // Get all the choices
    int getNumChoices() const;                                    // Get the number of choices available
    Scene* getOutcome(int index) const;                            // Get the outcome scene based on choice index

    // Battle-specific getter methods
    std::string getType() const;                                   // Get the type of the scene ("battle" or others)
    bool hasEnemy() const;                                         // Check if the scene has an enemy
    std::string getEnemyId() const;                                // Get the ID of the enemy in the scene
    bool hasNextScene() const;                                     // Check if there is a next scene
    std::string getNextScene() const;                              // Get the ID of the next scene

    // Other scene management methods
    void showScene() const;                                        // Display the scene description and choices
    void makeChoice(int choiceIndex);                              // Handle making a choice and go to the next scene
    void addOutcome(Scene* outcome);                               // Add a connected scene (outcome)

    // Battle-specific setter methods (not shown in original example, assuming you'd need them)
    void setType(const std::string& sceneType);                    // Set the scene type (e.g., "battle")
    void setEnemyId(const std::string& id);                        // Set the enemy ID
    void setNextSceneId(const std::string& nextScene);             // Set the ID of the next scene

private:
    std::string description;                                       // Description of the scene
    std::vector<Choice> choices;                                    // Choices available in the scene
    std::vector<Scene*> outcomes;                                   // Outcomes (next scenes) based on choices

    // Battle-specific data
    std::string type;                                              // Type of scene ("choice", "battle", etc.)
    std::optional<std::string> enemyId;                             // Enemy ID (only present if it's a battle scene)
    std::optional<std::string> nextSceneId;                         // ID of the next scene (if defined)
};
