#include "Carapace.h"
#include <cassert>
#include <iostream>
#include "GlobalConfig.h"

double Carapace::ETA_MAX = std::stod(GlobalConfig::getInstance().getConfig("ETA_MAX"));
double Carapace::OMEGA_MAX = std::stod(GlobalConfig::getInstance().getConfig("OMEGA_MAX"));

/**
 * @brief Constructeur de la classe Carapace
 * 
 * La carapace est initialisée avec un eta et un omega aléatoires entre ETA_MAX et OMEGA_MAX.
 * 
 * @param b 
 */
Carapace::Carapace(std::shared_ptr<IBestiole> b) {
    bestiole = b;
    eta = (ETA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    omega = (OMEGA_MAX - 1) * ((double)rand() / (double)RAND_MAX) + 1;
    cout << "(" << bestiole->getId() << "): const. par defaut Carapace" << endl;
}

/**
 * @brief Constructeur par copie de la classe Carapace
 * 
 * La carapace est initialisée avec un eta et un omega aléatoires entre ETA_MAX et OMEGA_MAX.
 * 
 * @param c 
 */
Carapace::Carapace(Carapace &c) {
    bestiole = c.bestiole->clone();
    eta = c.eta;
    omega = c.omega;
    cout << "(" << bestiole->getId() << "): const. par copie Carapace" << endl;
}

/**
 * @brief Destructeur de la classe Carapace
 * 
 */
Carapace::~Carapace() {
    cout << "(" << bestiole->getId() << "): dest Carapace" << endl;
}

/**
 * @brief Définit les limites de eta et omega
 * 
 * Appelé par le constructeur de l'Aquarium pour initialiser les limites de eta et omega avant la création des bestioles.
 * 
 * @param _OMEGA_MAX 
 * @param _ETA_MAX 
 */
void Carapace::setLimites(double _OMEGA_MAX, double _ETA_MAX) {
    assert(_OMEGA_MAX > 1);
    assert(_ETA_MAX > 1);
    OMEGA_MAX = _OMEGA_MAX;
    ETA_MAX = _ETA_MAX;
}

/**
 * @brief Clone la bestiole composée
 * 
 * En tant que décorateur, la carapace doit cloner la bestiole qu'elle décore.
 * 
 * @return std::shared_ptr<IBestiole>
 */

std::shared_ptr<IBestiole> Carapace::clone() {
    return make_shared<Carapace>(*this);
}

/**
 * @brief Mise à jour de la position de la Bestiole
 * 
 * Appel des méthodes de la bestiole composée en modifiant la vitesse.
 * 
 */
void Carapace::updatePos() {
    double vitesse = bestiole->getVitesse();
    // Modification de la vitesse
    bestiole->setVitesse(vitesse / eta);
    // Comportement normal de la bestiole composée
    bestiole->updatePos();
    // Restauration de la vitesse
    bestiole->setVitesse(vitesse);
}

/**
 * @brief Gestion des collisions
 * 
 * La résistance de la bestiole est multipliée par omega.
 * 
 * @return bool 
 */
bool Carapace::collision() {
    double resistance = bestiole->getResistance();
    bestiole->setResistance(omega * resistance); // les résistances se multiplient
    bool mort = bestiole->collision();
    bestiole->setResistance(resistance); // retour à la normale
    return mort;
}
