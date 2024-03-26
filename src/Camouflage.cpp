#include "Camouflage.h"
#include "IBestiole.h"
#include <iostream>
#include <cassert>
#include "GlobalConfig.h"

using namespace std;

double Camouflage::PSI_MIN = std::stod(GlobalConfig::getInstance().getConfig("PSI_MIN")); 
double Camouflage::PSI_MAX = std::stod(GlobalConfig::getInstance().getConfig("PSI_MAX")); 

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

double Camouflage::getDiscretion() const {
    double discretion = bestiole->getDiscretion();
    // Modification de la discrétion en cumulant les camouflages 
    bestiole->setDiscretion(discretion * (1 - psi) + psi);
    // Comportement normal de la bestiole composée
    double d = bestiole->getDiscretion();
    // Restauration de la discrétion
    bestiole->setDiscretion(discretion);
    return d;
}
