#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "Decorateur.h"

using namespace std;

/**
 * Un capteur des bestioles.
 * A une chance de détecter toute bestiole présente dans un cône à l'avant de la bestiole.
 */
class Oreilles : public Decorateur {
private:
    /**
     * Distance d'audition.
     * 0 < DELTA_O_MIN < deltaO < DELTA_O_MAX
     */
    double deltaO;
    /**
     * Capacité de détection.
     * 0 < GAMMA_O_MIN < gammaO < GAMMA_O_MAX < 1
     */
    double gammaO;
    static double DELTA_O_MIN;
    static double DELTA_O_MAX;
    static double GAMMA_O_MIN;
    static double GAMMA_O_MAX;

public:
    Oreilles(shared_ptr<IBestiole> b);
    Oreilles(Oreilles &o);
    ~Oreilles();
    virtual shared_ptr<IBestiole> clone() override;
    virtual bool detecter(shared_ptr<IBestiole> b) override;
};

#endif