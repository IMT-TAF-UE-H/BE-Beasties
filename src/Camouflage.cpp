#include "Camouflage.h"
#include "IBestiole.h"
#include <iostream>
#include <cassert>

using namespace std;

double Camouflage::PSI_MIN = 0;
double Camouflage::PSI_MAX = 1;

Camouflage::Camouflage(IBestiole* b) {
    bestiole = b;
    psi = (PSI_MAX - PSI_MIN) * ((double)rand() / (double)RAND_MAX) + PSI_MIN;
    cout << "const Camouflage par defaut sur bestiole " << bestiole->getId() << endl;
}

Camouflage::Camouflage(Camouflage &c) {
    bestiole = c.bestiole->clone();
    psi = c.psi;
    cout << "const Camouflage par copie sur bestiole " << bestiole->getId() << endl;
}

Camouflage::~Camouflage() {
    cout << "dest Camouflage" << endl;
}

void Camouflage::setLimites(double _PSI_MIN, double _PSI_MAX) {
    assert(_PSI_MIN > 0 && _PSI_MAX > _PSI_MIN && 1 > _PSI_MAX);
    PSI_MIN = _PSI_MIN;
    PSI_MAX = _PSI_MAX;
}

IBestiole* Camouflage::clone() {
    return new Camouflage(*this);
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