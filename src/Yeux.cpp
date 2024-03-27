#include "Yeux.h"
#include <cassert>
#include <iostream>
#include <math.h>
#include "GlobalConfig.h"

double Yeux::ALPHA_MIN = std::stod(GlobalConfig::getInstance().getConfig("ALPHA_MIN")); 
double Yeux::ALPHA_MAX = std::stod(GlobalConfig::getInstance().getConfig("ALPHA_MAX")); 
double Yeux::DELTA_Y_MIN = std::stod(GlobalConfig::getInstance().getConfig("DELTA_Y_MIN")); 
double Yeux::DELTA_Y_MAX = std::stod(GlobalConfig::getInstance().getConfig("DELTA_Y_MAX"));
double Yeux::GAMMA_Y_MIN = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_Y_MIN")); 
double Yeux::GAMMA_Y_MAX = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_Y_MAX")); 

/**
 * @brief Constructeur par défaut de la classe Yeux
 * 
 * @param b 
 */
Yeux::Yeux(std::shared_ptr<IBestiole> b) {
    bestiole = b;
    alpha = (ALPHA_MAX - ALPHA_MIN) * ((double)rand() / (double)RAND_MAX) + ALPHA_MIN;
    deltaY = (DELTA_Y_MAX - DELTA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_Y_MIN;
    gammaY = (GAMMA_Y_MAX - GAMMA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_Y_MIN;
    cout << "(" << bestiole->getId() << "): const. par defaut Yeux" << endl;
}

/**
 * @brief Constructeur par copie de la classe Yeux
 * 
 * @param y 
 */
Yeux::Yeux(Yeux &y) {
    bestiole = y.bestiole->clone();
    alpha = y.alpha;
    deltaY = y.deltaY;
    gammaY = y.gammaY;
    cout << "(" << bestiole->getId() << "): const. par copie Yeux" << endl;
}

/**
 * @brief Destructeur de la classe Yeux
 * 
 */
Yeux::~Yeux() {
    cout << "(" << bestiole->getId() << "): dest Yeux" << endl;
}

/**
 * @brief Setter des limites
 * 
 * @param _ALPHA_MIN 
 * @param _ALPHA_MAX 
 * @param _DELTA_Y_MIN 
 * @param _DELTA_Y_MAX 
 * @param _GAMMA_Y_MIN 
 * @param _GAMMA_Y_MAX 
 */
void Yeux::setLimites(double _ALPHA_MIN,
                      double _ALPHA_MAX,
                      double _DELTA_Y_MIN,
                      double _DELTA_Y_MAX,
                      double _GAMMA_Y_MIN,
                      double _GAMMA_Y_MAX) {
    assert(_ALPHA_MIN > 0 && _ALPHA_MAX > _ALPHA_MIN && 2 * M_PI > _ALPHA_MAX);
    assert(_DELTA_Y_MIN > 0 && _DELTA_Y_MAX > _DELTA_Y_MIN);
    assert(_GAMMA_Y_MIN > 0 && _GAMMA_Y_MAX > _GAMMA_Y_MIN && 1 > _GAMMA_Y_MAX);
    ALPHA_MIN = _ALPHA_MIN;
    ALPHA_MAX = _ALPHA_MAX;
    DELTA_Y_MIN = _DELTA_Y_MIN;
    DELTA_Y_MAX = _DELTA_Y_MAX;
    GAMMA_Y_MIN = _GAMMA_Y_MIN;
    GAMMA_Y_MAX = _GAMMA_Y_MAX;
}

/**
 * @brief Clone l'accessoire Yeux
 * 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> Yeux::clone() {
    return make_shared<Yeux>(*this);
}

/**
 * @brief Méthode qui détecte une bestiole
 * 
 * @param idBestiole 
 * @return true 
 * @return false 
 */
bool Yeux::detecter(int idBestiole) {
    bool detection; 
    double distance = bestiole->getDistance(idBestiole);
    double directionTo = bestiole->getDirectionTo(idBestiole);
    double direction = bestiole->getDirection();
    double angle = directionTo - direction;
    bool inField = (angle > alpha - M_PI / 2 && angle < alpha + M_PI / 2);
    bool inDistance = (distance < deltaY);
    bool inVision = (inField && inDistance);
    // détection si dans le champ de vision et dans la distance
    auto b = bestiole->getMilieu()->getBestiole(idBestiole);
    detection = inVision && (gammaY > b->getDiscretion());
    return detection;
}
