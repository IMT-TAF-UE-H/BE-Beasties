#include "Yeux.h"
#include <math.h>

Yeux::Yeux(shared_ptr<IBestiole> b) {
    bestiole = b;
    alpha = (ALPHA_MAX - ALPHA_MIN) * ((double)rand() / (double)RAND_MAX) + ALPHA_MIN;
    deltaY = (DELTA_Y_MAX - DELTA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_Y_MIN;
    gammaY = (GAMMA_Y_MAX - GAMMA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_Y_MIN;
}

bool Yeux::detecter(shared_ptr<IBestiole> b) {
    bool detection; // TODO : y mettre le résultat de la détection
    // TODO ...
    return detection || bestiole->detecter(b);
}
