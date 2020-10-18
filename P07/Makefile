CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: manga

debug: CXXFLAGS += -g
debug: manga

manga: main.o mainwin.o store.o product.o plant.o tool.o mulch.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o store.o product.o plant.o tool.o mulch.o $(GTKFLAGS) -o manga
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp $(GTKFLAGS) -o store.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp $(GTKFLAGS) -o product.o
plant.o: plant.cpp *.h
	$(CXX) $(CXXFLAGS) -c plant.cpp $(GTKFLAGS) -o plant.o
tool.o: tool.cpp *.h
	$(CXX) $(CXXFLAGS) -c tool.cpp $(GTKFLAGS) -o tool.o
mulch.o: mulch.cpp *.h
	$(CXX) $(CXXFLAGS) -c mulch.cpp $(GTKFLAGS) -o mulch.o

clean:
	rm -f *.o *.gch ~* a.out manga

