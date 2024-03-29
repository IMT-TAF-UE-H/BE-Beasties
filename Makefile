MAC_FLAGS = -I/opt/X14/include

SRC_DIR = src
OBJ_DIR = .
DECORATEURS = $(OBJ_DIR)/Camouflage.o $(OBJ_DIR)/Carapace.o $(OBJ_DIR)/Nageoire.o $(OBJ_DIR)/Oreilles.o $(OBJ_DIR)/Yeux.o
COMPORTEMENTS = $(OBJ_DIR)/CompKamikaze.o $(OBJ_DIR)/CompGregaire.o $(OBJ_DIR)/CompPeureuse.o $(OBJ_DIR)/CompPrevoyante.o $(OBJ_DIR)/CompMultiple.o
VERSION = c++14


# build
build: main
	rm -rf $(OBJ_DIR)/*.o


main: $(OBJ_DIR)/main.o $(OBJ_DIR)/Aquarium.o $(OBJ_DIR)/Bestiole.o $(OBJ_DIR)/Milieu.o $(OBJ_DIR)/BestioleFactory.o $(OBJ_DIR)/GlobalConfig.o $(DECORATEURS) $(COMPORTEMENTS) 
	g++ -Wall -std=$(VERSION) -o $@ $^ -I $(SRC_DIR) -lpthread $(MAC_FLAGS) -L/opt/X11/lib -lX11


$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(SRC_DIR)/Aquarium.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $< -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Aquarium.o : $(SRC_DIR)/Aquarium.h $(SRC_DIR)/Aquarium.cpp
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Aquarium.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Bestiole.o : $(SRC_DIR)/Bestiole.h $(SRC_DIR)/Bestiole.cpp $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h $(SRC_DIR)/IComportement.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Bestiole.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Milieu.o : $(SRC_DIR)/Milieu.h $(SRC_DIR)/Milieu.cpp
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Milieu.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/BestioleFactory.o : $(SRC_DIR)/BestioleFactory.h $(SRC_DIR)/BestioleFactory.cpp $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/BestioleFactory.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Camouflage.o : $(SRC_DIR)/Camouflage.h $(SRC_DIR)/Camouflage.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Camouflage.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Carapace.o : $(SRC_DIR)/Carapace.h $(SRC_DIR)/Carapace.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Carapace.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Nageoire.o : $(SRC_DIR)/Nageoire.h $(SRC_DIR)/Nageoire.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Nageoire.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Oreilles.o : $(SRC_DIR)/Oreilles.h $(SRC_DIR)/Oreilles.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Oreilles.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Yeux.o : $(SRC_DIR)/Yeux.h $(SRC_DIR)/Yeux.cpp $(SRC_DIR)/Decorateur.h $(SRC_DIR)/IBestiole.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/Yeux.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)


$(OBJ_DIR)/CompKamikaze.o : $(SRC_DIR)/CompKamikaze.h $(SRC_DIR)/CompKamikaze.cpp $(SRC_DIR)/IComportement.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/CompKamikaze.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/CompGregaire.o : $(SRC_DIR)/CompGregaire.h $(SRC_DIR)/CompGregaire.cpp $(SRC_DIR)/IComportement.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/CompGregaire.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/CompPeureuse.o : $(SRC_DIR)/CompPeureuse.h $(SRC_DIR)/CompPeureuse.cpp $(SRC_DIR)/IComportement.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/CompPeureuse.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/CompPrevoyante.o : $(SRC_DIR)/CompPrevoyante.h $(SRC_DIR)/CompPrevoyante.cpp $(SRC_DIR)/IComportement.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/CompPrevoyante.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/CompMultiple.o :  $(SRC_DIR)/CompMultiple.h $(SRC_DIR)/CompMultiple.cpp $(SRC_DIR)/IComportement.h $(SRC_DIR)/IBestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/CompMultiple.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/GlobalConfig.o : $(SRC_DIR)/GlobalConfig.h $(SRC_DIR)/GlobalConfig.cpp $(SRC_DIR)/Camouflage.h $(SRC_DIR)/Carapace.h $(SRC_DIR)/Nageoire.h $(SRC_DIR)/Oreilles.h $(SRC_DIR)/Yeux.h $(SRC_DIR)/Bestiole.h $(SRC_DIR)/BestioleFactory.h $(SRC_DIR)/Aquarium.h 
	g++ -Wall -std=$(VERSION) -c $(SRC_DIR)/GlobalConfig.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)


# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/*.o main
