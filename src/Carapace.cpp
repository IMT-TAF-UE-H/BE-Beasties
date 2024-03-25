#include "Carapace.h"
#include <cassert>
#include <iostream>
#include "GlobalConfig.h"

double Carapace::ETA_MAX = std::stod(GlobalConfig::getInstance().getConfig("ETA_MAX"));
double Carapace::OMEGA_MAX = std::stod(GlobalConfig::getInstance().getConfig("OMEGA_MAX"));

Carapace::Carapace(IBestiole* b) {
    bestiole = b;
    eta = (ETA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    omega = (OMEGA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    cout << "const Carapace par defaut sur bestiole " << bestiole->getId() << endl;
}

Carapace::Carapace(Carapace &c) {
    bestiole = c.bestiole->clone();
    eta = c.eta;
    omega = c.omega;
    cout << "const Carapace par copie sur bestiole " << bestiole->getId() << endl;
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

IBestiole* Carapace::clone() {
    return new Carapace(*this);
}

IBestiole* Carapace::cloner() {
    cout << "cloner Carapace" << endl;
    Carapace *c = new Carapace(bestiole->cloner());
    c->eta = eta;
    c->omega = omega;
    return c->clone();
}

void Carapace::updatePos() {
    double vitesse = bestiole->getVitesse();
    // Modification de la vitesse
    bestiole->setVitesse(vitesse / eta);
    // Comportement normal de la bestiole composée
    bestiole->updatePos();
    // Restauration de la vitesse
    bestiole->setVitesse(vitesse);
}

bool Carapace::collision() {
    double resistance = bestiole->getResistance();
    bestiole->setResistance(omega * resistance); // les résistances se multiplient
    bool mort = bestiole->collision();
    bestiole->setResistance(resistance); // retour à la normale
    return mort;
}
