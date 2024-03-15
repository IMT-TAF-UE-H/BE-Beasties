#include "Oreilles.h"
#include <cassert>
#include <iostream>
#include <math.h>

double Oreilles::DELTA_O_MIN = 0;
double Oreilles::DELTA_O_MAX = INFINITY;
double Oreilles::GAMMA_O_MIN = 0;
double Oreilles::GAMMA_O_MAX = 1;

Oreilles::Oreilles(shared_ptr<IBestiole> b) {
    bestiole = b;
    deltaO = (DELTA_O_MAX - DELTA_O_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_O_MIN;
    gammaO = (GAMMA_O_MAX - GAMMA_O_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_O_MIN;
    cout << "const Oreilles par defaut sur bestiole " << bestiole << endl;
}

Oreilles::Oreilles(Oreilles &o) {
    bestiole = o.bestiole->clone();
    deltaO = o.deltaO;
    gammaO = o.gammaO;
    cout << "const Oreilles par copie sur bestiole " << bestiole << endl;
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

shared_ptr<IBestiole> Oreilles::clone() {
    return make_shared<Oreilles>(*this);
}

bool Oreilles::detecter(shared_ptr<IBestiole> b) {
    bool detection; // TODO : Y mettre le résultat de la détection
    // TODO ...
    return detection || bestiole->detecter(b);
}
