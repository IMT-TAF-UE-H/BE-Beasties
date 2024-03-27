#include "Nageoire.h"
#include "IBestiole.h"
#include <iostream>
#include <cassert>
#include "GlobalConfig.h"

using namespace std;

/**
 * @brief Constructeur par défaut de la classe Nageoire
 * 
 * @param b 
 */
Nageoire::Nageoire(std::shared_ptr<IBestiole> b) {
    bestiole = b;
    nu = (NU_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    cout << "(" << bestiole->getId() << "): const. par defaut Nageoire" << endl;
}

/**
 * @brief Constructeur par copie de la classe Nageoire
 * 
 * @param n 
 */
Nageoire::Nageoire(Nageoire &n) {
    bestiole = n.bestiole->clone();
    nu = n.nu;
    cout << "(" << bestiole->getId() << "): const. par copie Nageoire" << endl;
}

/**
 * @brief Destructeur de la classe Nageoire
 * 
 */
Nageoire::~Nageoire() {
    cout << "(" << bestiole->getId() << "): dest Nageoire" << endl;
}

/**
 * @brief Setter de la vitesse maximale
 * 
 * @param _NU_MAX 
 */
void Nageoire::setLimites(double _NU_MAX) {
    assert(_NU_MAX > 1);
    NU_MAX = _NU_MAX;
}

/**
 * @brief Clone la nageoire
 * 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> Nageoire::clone() {
    return make_shared<Nageoire>(*this);
}

/**
 * @brief Mise à jour de la position de la bestiole composée
 * 
 */
void Nageoire::updatePos() {
    double vitesse = bestiole->getVitesse();
    // Modification de la vitesse
    bestiole->setVitesse(nu * vitesse);
    // Comportement normal de la bestiole composée
    bestiole->updatePos();
    // Restauration de la vitesse
    bestiole->setVitesse(vitesse);
}