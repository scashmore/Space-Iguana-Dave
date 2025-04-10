CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/Player.cpp
TESTS = tests/test_main.cpp src/Player.cpp

all: game

game: $(SRC)
	$(CXX) $(CXXFLAGS) -o game $(SRC)

test: $(TESTS)
	$(CXX) $(CXXFLAGS) -o test_runner $(TESTS)
	./test_runner

clean:
	rm -f game test_runner