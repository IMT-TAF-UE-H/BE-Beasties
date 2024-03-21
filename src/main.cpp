#include "Aquarium.h"
#include "Bestiole.h"
#include "Milieu.h"
#include "Oreilles.h"
#include "Nageoire.h"
#include "Carapace.h"

#include <iostream>

using namespace std;

int main() {
    // Création de l'écosystème
    Aquarium ecosysteme(640, 480, 30); // 640x480 pixels, 30ms de délai 

    // Récupération du milieu
    Milieu* milieu = ecosysteme.getMilieu();

    // Ajout de 100 bestioles
    for (int i = 1; i <= 100; ++i) {
      milieu->addBestiole();
    }
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
