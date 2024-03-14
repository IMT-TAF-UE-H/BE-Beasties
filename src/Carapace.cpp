#include "Carapace.h"
#include <cassert>
#include <iostream>

double Carapace::ETA_MAX = 100.;
double Carapace::OMEGA_MAX = 100.;

Carapace::Carapace(shared_ptr<IBestiole> b) {
    bestiole = b;
    eta = (ETA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    omega = (OMEGA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    cout << "const Carapace par defaut sur bestiole " << bestiole << endl;
}

Carapace::Carapace(Carapace &c) {
    bestiole = c.bestiole->clone();
    eta = c.eta;
    omega = c.omega;
    cout << "const Carapace par copie sur bestiole " << bestiole << endl;
}

Carapace::~Carapace() {
    cout << "dest Carapace" << endl;
}

void Carapace::setLimites(double _OMEGA_MAX, double _ETA_MAX) {
    assert(_OMEGA_MAX > 1);
    assert(_ETA_MAX > 1);
    OMEGA_MAX = _OMEGA_MAX;
    ETA_MAX = _ETA_MAX;
}

shared_ptr<IBestiole> Carapace::clone() {
    return make_shared<Carapace>(*this);
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
