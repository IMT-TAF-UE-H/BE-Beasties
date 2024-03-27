#include "Aquarium.h"
#include "Bestiole.h"
#include "Milieu.h"
#include "Oreilles.h"
#include "Nageoire.h"
#include "Carapace.h"
#include "GlobalConfig.h"

#include <iostream>

using namespace std;

/**
 * @brief Main
 * 
 * Crée un aquarium et lance la simulation.
 * 
 * @return int 
 */
int main() {
    // C40x480 pixels, 30ms de délai Création de l'écosystème
    GlobalConfig::loadConfigFromFile("default.conf");
    GlobalConfig::setLimites();
    Aquarium ecosysteme;
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
