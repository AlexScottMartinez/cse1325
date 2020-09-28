CXXFLAGS = --std=c++17

all: gate

gate: main.o gate.o *.h
	$(CXX) $(CXXFLAGS) main.o gate.o -o gate

gate.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

gate.o: gate.cpp *.h 
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o

clean:
	rm -f *.o *.gch ~* a.out gate 
