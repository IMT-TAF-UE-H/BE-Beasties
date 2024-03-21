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
    Aquarium ecosysteme(640, 480, 30); // 640x480 pixels, 30 bestioles

    // Récupération du milieu
    Milieu* milieu = ecosysteme.getMilieu();

    // Ajout de 100 bestioles
    for (int i = 1; i <= 100; ++i) {
      IBestiole* b = new Carapace(new Nageoire(new Oreilles(new Bestiole(milieu)))); // Ajout de décorateurs à la bestiole
      milieu->addBestiole(b); // Ajout de la bestiole au milieu
    }
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
