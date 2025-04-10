CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/Player.cpp src/Weapon.cpp src/Enemy.cpp src/Scene.cpp src/Story.cpp
TESTS = tests/test_main.cpp src/Player.cpp src/Weapon.cpp src/Enemy.cpp src/Scene.cpp src/Story.cpp

all: game

game: $(SRC)
	$(CXX) $(CXXFLAGS) -o game $(SRC)

test: $(TESTS)
	$(CXX) $(CXXFLAGS) -o test_runner $(TESTS)
	./test_runner

clean:
	rm -f game test_runner