MAC_FLAGS = -I/opt/X11/include

SRC_DIR = src
OBJ_DIR = .

# build
build: main
	rm -rf $(OBJ_DIR)/*.o

main : $(OBJ_DIR)/main.o $(OBJ_DIR)/Aquarium.o $(OBJ_DIR)/Bestiole.o $(OBJ_DIR)/Milieu.o
	g++ -Wall -std=c++11 -o $@ $^ -I $(SRC_DIR) -lpthread $(MAC_FLAGS) -L/opt/X11/lib -lX11

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(SRC_DIR)/Aquarium.h $(SRC_DIR)/Bestiole.h $(SRC_DIR)/Milieu.h
	g++ -Wall -std=c++11 -c $< -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Aquarium.o : $(SRC_DIR)/Aquarium.h $(SRC_DIR)/Aquarium.cpp
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Aquarium.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Bestiole.o : $(SRC_DIR)/Bestiole.h $(SRC_DIR)/Bestiole.cpp
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Bestiole.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

$(OBJ_DIR)/Milieu.o : $(SRC_DIR)/Milieu.h $(SRC_DIR)/Milieu.cpp
	g++ -Wall -std=c++11 -c $(SRC_DIR)/Milieu.cpp -o $@ -I $(SRC_DIR) $(MAC_FLAGS)

# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/*.o main
