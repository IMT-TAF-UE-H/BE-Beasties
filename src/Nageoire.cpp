#include "Nageoire.h"
#include "IBestiole.h"

using namespace std;

Nageoire::Nageoire(shared_ptr<IBestiole> b) {
    bestiole = b;
    nu = (NU_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
}

bool Nageoire::updatePos() {
    double vitesse = bestiole->getVitesse();
    // Modification de la vitesse
    bestiole->setVitesse(nu * vitesse);
    // Comportement normal de la bestiole composée
    bool mort = bestiole->updatePos();
    // Restauration de la vitesse
    bestiole->setVitesse(vitesse);
    return mort;
}