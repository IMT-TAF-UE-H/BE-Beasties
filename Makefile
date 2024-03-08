MAC_FLAGS = -I/opt/X11/include 

main : src/main.cpp src/Aquarium.o src/Bestiole.o src/Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lpthread $(MAC_FLAGS) -L/opt/X11/lib -lX11

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I . $(MAC_FLAGS)

Bestiole.o : src/Bestiole.h src/Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I . $(MAC_FLAGS)

Milieu.o : src/Milieu.h src/Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I . $(MAC_FLAGS)

clean:
	rm -rf *.o main

