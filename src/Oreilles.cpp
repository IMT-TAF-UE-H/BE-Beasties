#include "Oreilles.h"
#include <math.h>
#include <iostream>

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

shared_ptr<IBestiole> Oreilles::clone() {
    return make_shared<Oreilles>(*this);
}

bool Oreilles::detecter(shared_ptr<IBestiole> b) {
    bool detection; // TODO : Y mettre le résultat de la détection
    // TODO ...
    return detection || bestiole->detecter(b);
}
