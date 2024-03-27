#include "Camouflage.h"
#include "IBestiole.h"
#include <iostream>
#include <cassert>
#include "GlobalConfig.h"

using namespace std;

// Initialisation des limites de psi par parsing du fichier de configuration
double Camouflage::PSI_MIN = std::stod(GlobalConfig::getInstance().getConfig("PSI_MIN")); 
double Camouflage::PSI_MAX = std::stod(GlobalConfig::getInstance().getConfig("PSI_MAX")); 

/**
 * @brief Constructeur de la classe Camouflage
 * 
 * Le camouflage est initialisé avec un psi aléatoire entre PSI_MIN et PSI_MAX.
 * 
 * @param b 
 */
Camouflage::Camouflage(std::shared_ptr<IBestiole> b) {
    bestiole = b;
    psi = (PSI_MAX - PSI_MIN) * ((double)rand() / (double)RAND_MAX) + PSI_MIN;
    cout << "(" << bestiole->getId() << "): const. par defaut Camouflage" << endl;
}

/**
 * @brief Constructeur par copie de la classe Camouflage
 * 
 * Le camouflage est initialisé avec un psi aléatoire entre PSI_MIN et PSI_MAX.
 * 
 * @param c 
 */
Camouflage::Camouflage(Camouflage &c) {
    bestiole = c.bestiole->clone();
    psi = c.psi;
    cout << "(" << bestiole->getId() << "): const. par copie Camouflage" << endl;
}

/**
 * @brief Destructeur de la classe Camouflage
 * 
 */
Camouflage::~Camouflage() {
    cout << "(" << bestiole->getId() << "): dest Camouflage" << endl;
}

/**
 * @brief Définit les limites de psi
 * 
 * Appelé par le constructeur de l'Aquarium pour initialiser les limites de psi avant la création des bestioles.
 * 
 * @param _PSI_MIN 
 * @param _PSI_MAX 
 */
void Camouflage::setLimites(double _PSI_MIN, double _PSI_MAX) {
    assert(_PSI_MIN > 0 && _PSI_MAX > _PSI_MIN && 1 > _PSI_MAX);
    PSI_MIN = _PSI_MIN;
    PSI_MAX = _PSI_MAX;
}

/**
 * @brief Clone la bestiole composée
 * 
 * En tant que décorateur, le camouflage doit cloner la bestiole qu'il décore.
 * 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> Camouflage::clone() {
    return make_shared<Camouflage>(*this);
}

/**
 * @brief Récupère la discrétion de la bestiole composée
 * 
 * La discrétion est modifiée par le camouflage.
 * 
 * La formule de mise à jour de la discrétion est la suivante:
 * discrétion = discrétion_bestiole * (1 - psi) + psi
 * 
 * @return double 
 */
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
