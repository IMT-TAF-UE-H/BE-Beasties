MAC_FLAGS = -I/opt/X11/include

SRC_DIR = src
OBJ_DIR = .
DECORATEURS = $(OBJ_DIR)/Camouflage.o $(OBJ_DIR)/Carapace.o $(OBJ_DIR)/Nageoire.o $(OBJ_DIR)/Oreilles.o $(OBJ_DIR)/Yeux.o

# build
build: main
	rm -rf $(OBJ_DIR)/*.o

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/Aquarium.o $(OBJ_DIR)/Bestiole.o $(OBJ_DIR)/Milieu.o $(DECORATEURS)
	g++ -Wall -std=c++11 -o $@ $^ -I $(SRC_DIR) -lpthread $(MAC_FLAGS) -L/opt/X11/lib -lX11

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(SRC_DIR)/Aquarium.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=c++11 -c $< -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Aquarium.o : $(SRC_DIR)/Aquarium.h $(SRC_DIR)/Aquarium.cpp
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Aquarium.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Bestiole.o : $(SRC_DIR)/Bestiole.h $(SRC_DIR)/Bestiole.cpp $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Bestiole.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Milieu.o : $(SRC_DIR)/Milieu.h $(SRC_DIR)/Milieu.cpp
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Milieu.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Camouflage.o : $(SRC_DIR)/Camouflage.h $(SRC_DIR)/Camouflage.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Camouflage.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Carapace.o : $(SRC_DIR)/Carapace.h $(SRC_DIR)/Carapace.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Carapace.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Nageoire.o : $(SRC_DIR)/Nageoire.h $(SRC_DIR)/Nageoire.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Nageoire.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Oreilles.o : $(SRC_DIR)/Oreilles.h $(SRC_DIR)/Oreilles.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Oreilles.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Yeux.o : $(SRC_DIR)/Yeux.h $(SRC_DIR)/Yeux.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Yeux.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/*.o main
