#include "Oreilles.h"
#include <cassert>
#include <iostream>
#include <math.h>
#include "GlobalConfig.h"

double Oreilles::DELTA_O_MIN = std::stod(GlobalConfig::getInstance().getConfig("DELTA_O_MIN")); 
double Oreilles::DELTA_O_MAX = std::stod(GlobalConfig::getInstance().getConfig("DELTA_O_MAX")); 
double Oreilles::GAMMA_O_MIN = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_O_MIN")); 
double Oreilles::GAMMA_O_MAX = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_O_MAX"));

/**
 * @brief Constructeur par défaut de la classe Oreilles
 * 
 * @param b 
 */
Oreilles::Oreilles(std::shared_ptr<IBestiole> b) {
    bestiole = b;
    deltaO = (DELTA_O_MAX - DELTA_O_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_O_MIN;
    gammaO = (GAMMA_O_MAX - GAMMA_O_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_O_MIN;
    cout << "(" << bestiole->getId() << "): const. par defaut Oreilles" << endl;
}

/**
 * @brief Constructeur par copie de la classe Oreilles
 * 
 * @param o 
 */
Oreilles::Oreilles(Oreilles &o) {
    bestiole = o.bestiole->clone();
    deltaO = o.deltaO;
    gammaO = o.gammaO;
    cout << "(" << bestiole->getId() << "): const. par copie Oreilles" << endl;
}

/**
 * @brief Destructeur de la classe Oreilles
 * 
 */
Oreilles::~Oreilles() {
    cout << "(" << bestiole->getId() << "): dest Oreilles" << endl;
}

/**
 * @brief Setter des limites
 * 
 * @param _DELTA_O_MIN 
 * @param _DELTA_O_MAX 
 * @param _GAMMA_O_MIN 
 * @param _GAMMA_O_MAX 
 */
void Oreilles::setLimites(double _DELTA_O_MIN,
                          double _DELTA_O_MAX,
                          double _GAMMA_O_MIN,
                          double _GAMMA_O_MAX) {
    assert(_DELTA_O_MIN > 0 && _DELTA_O_MAX > _DELTA_O_MIN);
    assert(_GAMMA_O_MIN > 0 && _GAMMA_O_MAX > _GAMMA_O_MIN && 1 > _GAMMA_O_MAX);
    DELTA_O_MIN = _DELTA_O_MIN;
    DELTA_O_MAX = _DELTA_O_MAX;
    GAMMA_O_MIN = _GAMMA_O_MIN;
    GAMMA_O_MAX = _GAMMA_O_MAX;
}

/**
 * @brief Clone une oreille
 * 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> Oreilles::clone() {
    return make_shared<Oreilles>(*this);
}

/**
 * @brief Méthode qui détecte une bestiole
 * 
 * @param idBestiole 
 * @return true 
 * @return false 
 */
bool Oreilles::detecter(int idBestiole) {
    bool detection;
    bool inDistance = bestiole->getDistance(idBestiole) < deltaO;
    // detecte si la bestiole est dans la distance de detection et si elle est detectable
    auto b = bestiole->getMilieu()->getBestiole(idBestiole);
    detection = inDistance && (gammaO > b->getDiscretion());
    return detection;
}
