# 🦎 Space Iguana Dave

A silly, terminal-based space adventure RPG about Dave, a smooth-talking space iguana armed with questionable weapons and a surplus of coolness. Explore, fight bizarre enemies (like a villainous Palmetto Tree), collect odd items, and shape your own absurd destiny.

---

## 🚀 Technologies Used

- **C++17**
- **CMake** (for building)
- **nlohmann/json** (for parsing JSON data)
- **Termios** (for single-key input handling on Unix/macOS)
- **Apple Silicon (arm64)** compatible

---

## 🎮 How to Play

1. **Clone the repo**:
   ```bash
   git clone https://github.com/yourusername/space-iguana-dave.git
   cd space-iguana-dave
   ```

2. **Ensure you have dependencies**:
   - C++17-compatible compiler
   - CMake 3.15+
   - [nlohmann/json](https://github.com/nlohmann/json) (easiest via [vcpkg](https://github.com/microsoft/vcpkg))

   Example using vcpkg:
   ```bash
   ./vcpkg install nlohmann-json
   ```

3. **🛠️ Quick Build Instructions**:

    ```bash
    # Clone the repo and enter the folder
    git clone https://github.com/yourusername/Space-Iguana-Dave.git
    cd Space-Iguana-Dave

    # Build the project (replace with your path to vcpkg if different)
    cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
    cmake --build build

    # Run the game
    ./build/space_iguana


---

## 🎯 Planned Features

- ✅ Text-based story progression system using JSON scenes
- ✅ Weapons and inventory system
- ✅ Key items for story progression
- ✅ Stylized title screen and menu
- ⏳ Turn-based battle system with:
  - Attack, Defend, Use Item, Run
  - Random enemy encounters
  - Unlockable attack moves
- ⏳ Level design and free exploration
- ⏳ Equipment and skill upgrades
- ⏳ Puzzle-based story segments
- ⏳ Boss battles (🌴 Palmetto Tree)

---

## 🎥 Gameplay Preview

![Space Iguana Dave Gameplay](readme_assets/gameplay_example.mp4)

---

## 🧪 Testing & Contributions

- Tests are coming soon!
- Feel free to fork and make pull requests.
- If you're enjoying Dave's weird space trip, leave a star! ⭐

---

## 🧃 Coolness Scale

> This game runs on coolness. Stay weird, stay rad.