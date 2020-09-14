CXXFLAGS += --std=c++17

all: game

debug: CXXFLAGS += -g
debug: game

rebuild: clean game

game: main.cpp board.cpp tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp board.cpp tile.cpp

clean:
	-rm -f *.o *.gch *~ game
