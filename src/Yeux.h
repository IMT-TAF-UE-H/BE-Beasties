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
    static double ALPHA_MIN;
    static double ALPHA_MAX;
    static double DELTA_Y_MIN;
    static double DELTA_Y_MAX;
    static double GAMMA_Y_MIN;
    static double GAMMA_Y_MAX;

public:
    Yeux(std::shared_ptr<IBestiole> b);
    Yeux(Yeux &y);
    ~Yeux() override;
    static void setLimites(double _ALPHA_MIN,
                           double _ALPHA_MAX,
                           double _DELTA_Y_MIN,
                           double _DELTA_Y_MAX,
                           double _GAMMA_Y_MIN,
                           double _GAMMA_Y_MAX);
    std::shared_ptr<IBestiole> clone() override;
    bool detecter(int idBestiole) override;
};

#endif