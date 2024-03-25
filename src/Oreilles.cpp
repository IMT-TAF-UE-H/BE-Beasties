#include "Oreilles.h"
#include <cassert>
#include <iostream>
#include <math.h>
#include "GlobalConfig.h"

double Oreilles::DELTA_O_MIN = std::stod(GlobalConfig::getInstance().getConfig("DELTA_O_MIN")); 
double Oreilles::DELTA_O_MAX = std::stod(GlobalConfig::getInstance().getConfig("DELTA_O_MAX")); 
double Oreilles::GAMMA_O_MIN = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_O_MIN")); 
double Oreilles::GAMMA_O_MAX = std::stod(GlobalConfig::getInstance().getConfig("GAMMA_O_MAX"));

Oreilles::Oreilles(IBestiole *b) {
    bestiole = b;
    deltaO = (DELTA_O_MAX - DELTA_O_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_O_MIN;
    gammaO = (GAMMA_O_MAX - GAMMA_O_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_O_MIN;
    cout << "const Oreilles par defaut sur bestiole " << bestiole->getId() << endl;
}

Oreilles::Oreilles(Oreilles &o) {
    bestiole = o.bestiole->clone();
    deltaO = o.deltaO;
    gammaO = o.gammaO;
    cout << "const Oreilles par copie sur bestiole " << bestiole->getId() << endl;
}

Oreilles::~Oreilles() {
    cout << "dest Oreilles" << endl;
}

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

IBestiole *Oreilles::clone() {
    return new Oreilles(*this);
}

IBestiole *Oreilles::cloner() {
    cout << "cloner Oreilles" << endl;
    Oreilles *o = new Oreilles(bestiole->cloner());
    o->deltaO = deltaO;
    o->gammaO = gammaO;
    return o->clone();
}

bool Oreilles::detecter(int idBestiole) {
    bool detection;
    bool inDistance = bestiole->getDistance(idBestiole) < deltaO;
    // detecte si la bestiole est dans la distance de detection et si elle est detectable
    IBestiole *b = bestiole->getMilieu()->getBestiole(idBestiole);
    detection = inDistance && (gammaO > b->getDiscretion());
    return detection;
}
