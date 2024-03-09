#include "Camouflage.h"
#include "IBestiole.h"

using namespace std;

Camouflage::Camouflage(shared_ptr<IBestiole> b) {
    bestiole = b;
    psi = (PSI_MAX - PSI_MIN) * ((double)rand() / (double)RAND_MAX) + PSI_MIN;
}

bool Camouflage::detectable() {
    double discretion = bestiole->getDiscretion();
    // Modification de la discrétion en cumulant les probabilités
    bestiole->setDiscretion(discretion * (1 - psi) + psi);
    // Comportement normal de la bestiole composée
    bool detectable = bestiole->detectable();
    // Restauration de la discrétion
    bestiole->setDiscretion(discretion);
    return detectable;
}