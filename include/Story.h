#pragma once

#include "Scene.h"
#include "Enemy.h"
#include "Item.h"
#include "Battle.h"
#include "Player.h"
#include "Weapon.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <nlohmann/json.hpp>
#include <map>

class Story {
public:
    Story();  // Constructor to initialize the story

    void createStory();  // Create the story by loading and linking scenes
    void processJsonFile(const std::string& filename, const nlohmann::json& fileData);  // Process each JSON file
    void loadSceneFile(const std::string& filename, const nlohmann::json& sceneData);  // Load scenes from JSON data
    void loadEnemies(const nlohmann::json& enemyData);  // Load enemies from JSON data
    void loadItems(const nlohmann::json& itemData);  // Load items from JSON data (newly added)
    void loadKeyItems(const nlohmann::json& keyItemData);  // Load key items from JSON data (newly added)
    void loadBattleScenes(const nlohmann::json& battleData);  // Load battle scenes from JSON data (newly added)
    void loadEnemyDeaths(const nlohmann::json& enemyDeathData);  // Load enemy death data (newly added)
    void loadWeapons(const nlohmann::json& weaponData);  // Load weapons from JSON data (newly added)
    void startBattle(Scene* battleScene); //starts battle scenes

    
    void linkScenes();  // Link scenes based on the "next" choices
    void goToScene(const std::string& id);  // Move to a new scene based on ID
    void displayCurrentScene();  // Display the current scene's description and choices
    Scene* getCurrentScene() const;  // Get the current scene
    Scene* getNextScene(int choiceIndex);  // Get the next scene based on player's choice
    void reset();  // Reset the story to the starting scene
    std::string getCurrentSceneIdFromChoice(int index);  // Get the next scene ID from a choice
    int getUserChoice(int minChoice, int maxChoice); //Get user inputs

    void playScene(const std::string& sceneId);  // Added playScene method declaration
    Enemy* loadEnemyById(const std::string& id);  // Added loadEnemyById method declaration

    void handleBattleOutcome(bool playerWon);
    void transitionToNextScene(const std::string& nextSceneId);

private:
    std::map<std::string, Scene*> scenes;  // Map of all scenes by their ID
    std::map<std::string, Weapon> weapons;  // Map to store loaded weapons
    std::map<std::string, Enemy> enemies;

    std::string currentSceneId;  // Current scene ID
};