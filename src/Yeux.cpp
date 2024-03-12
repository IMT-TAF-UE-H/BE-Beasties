#include "Yeux.h"
#include <math.h>
#include <iostream>

Yeux::Yeux(shared_ptr<IBestiole> b) {
    bestiole = b;
    alpha = (ALPHA_MAX - ALPHA_MIN) * ((double)rand() / (double)RAND_MAX) + ALPHA_MIN;
    deltaY = (DELTA_Y_MAX - DELTA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + DELTA_Y_MIN;
    gammaY = (GAMMA_Y_MAX - GAMMA_Y_MIN) * ((double)rand() / (double)RAND_MAX) + GAMMA_Y_MIN;
    cout << "const Yeux par defaut sur bestiole " << bestiole << endl;
}

Yeux::Yeux(Yeux &y) {
    bestiole = y.bestiole->clone();
    alpha = y.alpha;
    deltaY = y.deltaY;
    gammaY = y.gammaY;
    cout << "const Yeux par copie sur bestiole " << bestiole << endl;
}

Yeux::~Yeux() {
    cout << "dest Yeux" << endl;
}

shared_ptr<IBestiole> Yeux::clone() {
    return make_shared<Yeux>(this);
}

bool Yeux::detecter(shared_ptr<IBestiole> b) {
    bool detection; // TODO : y mettre le résultat de la détection
    // TODO ...
    return detection || bestiole->detecter(b);
}
