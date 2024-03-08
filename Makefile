MAC_FLAGS = -I/opt/X11/include 

main : main.cpp Aquarium.o Bestiole.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lpthread $(MAC_FLAGS) -L/opt/X11/lib -lX11

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I . $(MAC_FLAGS)

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I . $(MAC_FLAGS)

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I . $(MAC_FLAGS)

clean:
	rm -rf *.o main

