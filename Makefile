# build
build: main
	rm -rf *.o

main : src/main.cpp Aquarium.o Bestiole.o Milieu.o
	g++ -Wall -std=c++11 -o main src/main.cpp Aquarium.o Bestiole.o Milieu.o -I ./src -lX11 -lpthread

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c src/Aquarium.cpp -I ./src

Bestiole.o : src/Bestiole.h src/Bestiole.cpp
	g++ -Wall -std=c++11  -c src/Bestiole.cpp -I ./src

Milieu.o : src/Milieu.h src/Milieu.cpp
	g++ -Wall -std=c++11  -c src/Milieu.cpp -I ./src

# clean
.PHONY: clean
clean:
	rm -rf main *.o
