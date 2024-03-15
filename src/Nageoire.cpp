#include "Nageoire.h"
#include "IBestiole.h"
#include <iostream>
#include <cassert>

using namespace std;

double Nageoire::NU_MAX = 100.;

Nageoire::Nageoire(shared_ptr<IBestiole> b) {
    bestiole = b;
    nu = (NU_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
}

Nageoire::Nageoire(Nageoire &n) {
    bestiole = n.bestiole->clone();
    nu = n.nu;
    cout << "const Nageoire par defaut sur bestiole " << bestiole << endl;
}

Nageoire::~Nageoire() {
    cout << "dest Nageoire" << endl;
}

void Nageoire::setLimites(double _NU_MAX) {
    assert(_NU_MAX > 1);
    NU_MAX = _NU_MAX;
}

shared_ptr<IBestiole> Nageoire::clone() {
    return make_shared<Nageoire>(*this);
    cout << "const Nageoire par copie sur bestiole " << bestiole << endl;
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