#ifndef _YEUX_H_
#define _YEUX_H_

#include "Decorateur.h"

using namespace std;

/**
 * Un capteur des bestioles.
 * A une chance de détecter toute bestiole présente dans un cône à l'avant de la bestiole.
 */
class Yeux : public Decorateur {
private:
    /**
     * Champ angulaire de vision.
     * 0 < ALPHA_MIN < alpha < ALPHA_MAX < 2*pi
     */
    double alpha;
    /**
     * Distance de vision.
     * 0 < DELTA_Y_MIN < deltaY < DELTA_Y_MAX
     */
    double deltaY;
    /**
     * Capacité de détection.
     * 0 < GAMMA_Y_MIN < gammaY < GAMMA_Y_MAX < 1
     */
    double gammaY;
    static const double ALPHA_MIN;
    static const double ALPHA_MAX;
    static const double DELTA_Y_MIN;
    static const double DELTA_Y_MAX;
    static const double GAMMA_Y_MIN;
    static const double GAMMA_Y_MAX;

public:
    Yeux(shared_ptr<IBestiole> b);
    virtual bool detecter(shared_ptr<IBestiole> b) override;
};

#endif