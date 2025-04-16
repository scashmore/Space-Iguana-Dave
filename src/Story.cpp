#include "Story.h"
#include "Enemy.h"
#include "Battle.h"
#include "Player.h"
#include "Weapon.h" 
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <map>

namespace fs = std::filesystem;
using json = nlohmann::json;

Story::Story() {
    createStory();
}

void Story::createStory() {
    std::string dataDir = "data";  // Path to the 'data' folder

    // Iterate through all files in the data directory
    for (const auto& entry : fs::directory_iterator(dataDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".json") {
            // Open the JSON file
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "❌ Failed to open file: " << entry.path() << "\n";
                continue;
            }

            json fileData;
            file >> fileData;  // Parse the JSON file

            // Handle file contents dynamically
            processJsonFile(entry.path().filename().string(), fileData);
        }
    }

    // Ensure scenes are linked properly after processing all files
    linkScenes();
}

void Story::processJsonFile(const std::string& filename, const json& fileData) {
    // If it's an object where the values are scenes
    if (fileData.is_object()) {
        bool looksLikeScenes = true;
        for (const auto& [id, node] : fileData.items()) {
            if (!node.contains("description") || !node.contains("choices")) {
                looksLikeScenes = false;
                break;
            }
        }

        if (looksLikeScenes) {
            loadSceneFile(filename, fileData);
            return;
        }
    }

    if (filename == "enemies.json") {
        loadEnemies(fileData);
    } else if (filename == "items.json") {
        loadItems(fileData);
    } else if (filename == "keyItems.json") {
        loadKeyItems(fileData);
    } else if (filename == "battle.json") {
        loadBattleScenes(fileData);
    } else if (filename == "enemyDeaths.json") {
        loadEnemyDeaths(fileData);
    } else if (filename == "weapons.json") {
        loadWeapons(fileData);
    } else {
        std::cout << "⚠️ Unknown file type: " << filename << "\n";
    }
}

void Story::loadWeapons(const json& weaponData) {
    for (auto& weapon : weaponData) {
        if (weapon.contains("id") && weapon.contains("name") && weapon.contains("description") && weapon.contains("damage") && weapon.contains("type")) {
            std::string id = weapon["id"];
            std::string name = weapon["name"];
            std::string description = weapon["description"];
            int damage = weapon["damage"];
            std::string type = weapon["type"];

            // Assuming Weapon is a class with these parameters
            Weapon newWeapon(id, name, description, damage, type);

            // Store the weapon in the map using its id as the key
            weapons[id] = newWeapon;

            std::cout << "Loaded weapon: " << name << " (" << type << ") with damage: " << damage << "\n";
        } else {
            std::cerr << "⚠️ Missing required keys in weapon data\n";
        }
    }
}

void Story::loadSceneFile(const std::string& filename, const json& sceneData) {
    // Iterate over the scene data and load each scene
    for (auto& [id, node] : sceneData.items()) {
        // Ensure the required fields are present
        if (node.contains("description") && node.contains("choices")) {
            std::string description = node["description"];
            std::vector<Choice> choices;

            // Load choices, ensuring each choice has the necessary data
            for (const auto& choice : node["choices"]) {
                if (choice.contains("text") && choice.contains("next")) {
                    std::string text = choice["text"];
                    std::string next = choice["next"];
                    choices.push_back({text, next});
                } else {
                    std::cerr << "⚠️ Incomplete choice data in scene " << id << "\n";
                }
            }

            // Create scene and add it to scenes map
            Scene* scene = new Scene(description, choices);

            // Set type if specified (default is "choice")
            if (node.contains("type")) {
                scene->setType(node["type"]);
            }

            // Set enemy ID if it's a battle scene
            if (scene->getType() == "battle" && node.contains("enemy")) {
                scene->setEnemyId(node["enemy"]);
            }

            // Set next scene ID if provided
            if (node.contains("next")) {
                scene->setNextSceneId(node["next"]);
            }

            scenes[id] = scene;
        } else {
            std::cerr << "⚠️ Missing required keys in scene " << id << "\n";
        }
    }
}

void Story::loadEnemies(const json& enemyData) {
    for (auto& [id, enemy] : enemyData.items()) {
        if (enemy.contains("name") && enemy.contains("health") && enemy.contains("damage")) {
            std::string name = enemy["name"];
            int health = enemy["health"];
            int damage = enemy["damage"];

            Enemy newEnemy(name, health, damage);
            enemies[id] = newEnemy;

            std::cout << "✅ Loaded enemy: " << name << " (ID: " << id << ", HP: " << health << ", DMG: " << damage << ")\n";
        } else {
            std::cerr << "⚠️ Missing required keys in enemy data (ID: " << id << ")\n";
        }
    }
}



void Story::loadItems(const json& itemData) {
    // Load items from the items.json file
    for (auto& item : itemData) {
        if (item.contains("name") && item.contains("type")) {
            std::string name = item["name"];
            std::string type = item["type"]; // e.g., "weapon", "health", etc.
            // Process item data
            std::cout << "Loaded item: " << name << " of type: " << type << "\n";
        } else {
            std::cerr << "⚠️ Missing required keys in item data\n";
        }
    }
}

void Story::loadKeyItems(const json& keyItemData) {
    // Load key items from the keyItems.json file
    for (auto& keyItem : keyItemData) {
        if (keyItem.contains("name") && keyItem.contains("description")) {
            std::string name = keyItem["name"];
            std::string description = keyItem["description"];
            // Process key item data
            std::cout << "Loaded key item: " << name << " with description: " << description << "\n";
        } else {
            std::cerr << "⚠️ Missing required keys in key item data\n";
        }
    }
}

void Story::loadBattleScenes(const json& battleData) {
    // Load battle scenes from battle.json
    for (auto& battle : battleData) {
        if (battle.contains("sceneId") && battle.contains("description") && battle.contains("enemyId")) {
            std::string sceneId = battle["sceneId"];
            std::string description = battle["description"];
            std::string enemyId = battle["enemyId"];
            // Process battle data
            std::cout << "Loaded battle scene: " << sceneId << " with enemy: " << enemyId << "\n";
        } else {
            std::cerr << "⚠️ Missing required keys in battle scene data\n";
        }
    }
}

void Story::loadEnemyDeaths(const json& deathData) {
    // Load enemy death data (this could link to scenes, stats, etc.)
    for (auto& death : deathData) {
        if (death.contains("enemyId") && death.contains("outcome")) {
            std::string enemyId = death["enemyId"];
            std::string outcome = death["outcome"];
            // Process death data
            std::cout << "Loaded enemy death: " << enemyId << " with outcome: " << outcome << "\n";
        } else {
            std::cerr << "⚠️ Missing required keys in enemy death data\n";
        }
    }
}

void Story::linkScenes() {
    // Iterate over each scene
    for (auto& [sceneId, scene] : scenes) {
        // If the scene has no choices, skip it
        if (scene->getChoices().empty()) continue;

        // Temporary vector to hold choices (as pairs of text and next scene ID)
        std::vector<std::pair<std::string, std::string>> localChoices;

        // Iterate over each choice in the scene
        for (auto choice : scene->getChoices()) {
            // Now 'choice' is a non-const reference
            if (!choice.next.empty()) {
                std::string nextId = choice.next;  // Get the next scene ID
                std::string text = choice.text;    // Get the choice text

                // Store the choice in localChoices vector
                localChoices.push_back({text, nextId});

                // Check if the next scene exists in the scenes map
                if (scenes.count(nextId)) {
                    // Update the 'next' field of the choice (since it's now non-const)
                    choice.next = nextId;
                } else {
                    std::cerr << "⚠️ Scene ID not found for linking: " << nextId << " in scene " << sceneId << "\n";
                }
            }
        }


        // May want to store or process 'localChoices' later as part of the scene logic
        // (e.g., store it as part of the scene or use it elsewhere)
    }
}


Scene* Story::getCurrentScene() const {
    if (!scenes.count(currentSceneId)) {
        std::cerr << "❌ getCurrentScene: Invalid currentSceneId: " << currentSceneId << "\n";
        return nullptr;
    }
    return scenes.at(currentSceneId);
}

Scene* Story::getNextScene(int choiceIndex) {
    Scene* current = getCurrentScene();
    if (!current) {
        std::cout << "⚠️ No current scene loaded.\n";
        return nullptr;
    }

    const auto& choices = current->getChoices();

    if (choiceIndex < 0 || choiceIndex >= static_cast<int>(choices.size())) {
        std::cout << "❌ Invalid choice index: " << choiceIndex << "\n";
        return nullptr;
    }

    std::string nextId = choices[choiceIndex].next;

    if (scenes.find(nextId) == scenes.end()) {
        std::cout << "⚠️ Scene not found for next ID: " << nextId << "\n";
        return nullptr;
    }

    goToScene(nextId);
    return getCurrentScene();
}

void Story::goToScene(const std::string& id) {
    if (id.empty() || id == "END") {
        std::cout << "🛑 The story has concluded.\n";
        currentSceneId = "";  // Clear or mark as ended
        return;
    }

    std::cout << "Going to scene with ID: " << id << std::endl;  // Debug message
    
    try {
        if (!scenes.count(id)) {
            std::cerr << "❌ Scene not found: " << id << "\n";
            return;
        }
        currentSceneId = id;
    } catch (const std::out_of_range& e) {
        std::cerr << "Scene with ID " << id << " not found!" << std::endl;
        // Handle error or fallback here
    }
}

std::string Story::getCurrentSceneIdFromChoice(int index) {
    json fullJson;
    std::ifstream inFile("data/battle.json"); // Adjust if your scenes are merged
    if (!inFile.is_open()) return "";

    inFile >> fullJson;

    auto& sceneData = fullJson[currentSceneId];
    if (!sceneData.contains("choices")) return "";

    const auto& choices = sceneData["choices"];
    if (index < 0 || index >= choices.size()) return "";

    return choices[index]["next"];
}

void Story::reset() {
    currentSceneId = "start";
}

void Story::displayCurrentScene() const {
    auto it = scenes.find(currentSceneId);
    if (it == scenes.end()) {
        std::cerr << "❌ displayCurrentScene: Scene not found: " << currentSceneId << "\n";
        return;
    }
    it->second->showScene();
}

Enemy Story::loadEnemyById(const std::string& id) {
    if (!enemies.count(id)) {
        throw std::runtime_error("❌ Enemy not found: " + id);
    }
    return enemies.at(id);
}

