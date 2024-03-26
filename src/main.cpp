#include "Aquarium.h"
#include "Bestiole.h"
#include "Milieu.h"
#include "Oreilles.h"
#include "Nageoire.h"
#include "Carapace.h"
#include "GlobalConfig.h"

#include <iostream>

using namespace std;

int main() {
    // C40x480 pixels, 30ms de délai Création de l'écosystème
    int width = std::stoi(GlobalConfig::getInstance().getConfig("width"));
    int height = std::stoi(GlobalConfig::getInstance().getConfig("height"));
    int delay = std::stoi(GlobalConfig::getInstance().getConfig("delay"));
    Aquarium ecosysteme(width, height, delay);
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
