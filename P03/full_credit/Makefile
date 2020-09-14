CXXFLAGS += --std=c++17

all: game

debug: CXXFLAGS += -g
debug: game

rebuild: clean game

game: Main.cpp Board.cpp Tile.cpp
	$(CXX) $(CXXFLAGS) Main.cpp Board.cpp Tile.cpp -o game

clean:
	rm -f *.o *.gch ~* a.out game
