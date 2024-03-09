#include "Carapace.h"

Carapace::Carapace(shared_ptr<IBestiole> b) {
    bestiole = b;
    eta = (ETA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    omega = (OMEGA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
}

bool Carapace::updatePos() {
    double vitesse = bestiole->getVitesse();
    // Modification de la vitesse
    bestiole->setVitesse(vitesse / eta);
    // Comportement normal de la bestiole composée
    bool mort = bestiole->updatePos();
    // Restauration de la vitesse
    bestiole->setVitesse(vitesse);
    return mort;
}

bool Carapace::collision(shared_ptr<IBestiole> b) {
    double resistance = bestiole->getResistance();
    bestiole->setResistance(omega * resistance); // les résistances se multiplient
    bool mort = bestiole->collision(b);
    bestiole->setResistance(resistance); // retour à la normale
    return mort;
}
