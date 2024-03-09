#include "Oreilles.h"
#include <math.h>

Oreilles::Oreilles(shared_ptr<IBestiole> b) {
    bestiole = b;
    deltaO = (DELTA_O_MAX - DELTA_O_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_O_MIN;
    gammaO = (GAMMA_O_MAX - GAMMA_O_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_O_MIN;
}

bool Oreilles::detecter(shared_ptr<IBestiole> b) {
    bool detection; // TODO : Y mettre le résultat de la détection
    // TODO ...
    return detection || bestiole->detecter(b);
}
